(ns dice.core
(:require [clojure.core.reducers :as r]
          [clojure.string        :as str])
 (:gen-class))

(defn parse-int [s]
   (Integer. (re-find  #"\d+" s )))

(defn roll
  [nroll nfaces]
  (->> (repeat nroll nfaces)
       (r/map (fn [x](+ (rand-int (- x 1)) 1)))
       (r/fold +)))

(defn result
  [s]
  (apply roll (map parse-int (str/split s #"d"))))

(defn parsefile
  [filename]
   (r/map result (str/split-lines(slurp filename))))

(defn -main [& args]
(prn (format "args=%s" args))
  (if (not (empty? args))
    (do
      (time(parsefile (first args))))))
