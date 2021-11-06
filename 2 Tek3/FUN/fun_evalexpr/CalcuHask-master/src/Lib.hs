module Lib
    ( someFunc
    ) where

someFunc :: IO ()
someFunc = putStrLn "someFunc"

--- Function Flop reversing a pair
flop :: (a,a) -> (a,a)
flop (x,y) = (y, x)
