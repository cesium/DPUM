module Main where

import Control.Concurrent
import Control.Concurrent.STM.TBQueue
import GHC.Conc
import System.Random
import GHC.Natural

data Shop = Shop {
    seats :: TVar Natural,
    queue :: TBQueue Natural
}

-- Aux functions
initShop :: Natural -> STM Shop
initShop nSeats = do
    s <- newTVar nSeats
    q <- newTBQueue nSeats
    return $ Shop s q

threadDelayR :: Int -> Int -> IO ()
threadDelayR l h = getStdRandom (randomR (l, h)) >>= threadDelay

seatOrKick :: Shop -> Natural -> IO (Maybe ())
seatOrKick s c = do
    ns <- atomically . readTVar . seats $ s
    if ns > 0 then atomically $ do
        writeTVar (seats s) (ns-1)
        fmap (const (Just ())) $ writeTBQueue (queue s) c
    else return Nothing

-- Main logic
enterShop :: Shop -> Natural -> IO ()
enterShop s c = do
    putStrLn $ "[*] Client enters shop " ++ show c
    decision <- seatOrKick s c
    case decision of
      Just _  -> putStrLn $  "[*] Seat available for client " ++ show  c
      Nothing -> putStrLn $ "[*] Kicking client " ++ show c

createCustomers :: Shop -> IO ()
createCustomers shop = createCustomer shop 1
  where
    createCustomer :: Shop -> Natural -> IO ()
    createCustomer s n =
      threadDelayR 100000 2000000 >>
      forkIO (enterShop s n) >>
      createCustomer shop (n+1)

cutHair :: Shop -> IO ()
cutHair s = do
    c <- atomically $ readTBQueue (queue s)
    atomically $ do
        ns <- readTVar (seats s)
        writeTVar (seats s) (ns+1)
    putStrLn $ "[+] Cutting hair of client " ++ show c
    threadDelayR 100000 10000000
    putStrLn $ "[+] Done cutting hair of client " ++ show c

work :: Shop -> IO ThreadId
work s = forkIO loop
  where
    loop :: IO ()
    loop = cutHair s >> loop

main :: IO ()
main = atomically (initShop 4) >>=
  \s -> work s >> createCustomers s
