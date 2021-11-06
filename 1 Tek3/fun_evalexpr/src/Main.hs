module Main where

import Text.Printf
import System.Environment
import System.Exit
import Evalexpr

main = do
    calcul <- string
    let x = compute calcul
    print (x)
    return 0

string :: IO String
string = do
    args <- getArgs
    case args of
        a:as -> return a
        otherwise -> exitWith (ExitFailure 84)