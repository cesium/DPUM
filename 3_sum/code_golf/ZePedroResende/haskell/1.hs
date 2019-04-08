import Data.List;main=interact$unlines.map(unwords.map show).nub.sort.filter(\x->0==sum x&&3==length x).subsequences.sort.map read.words
