module Main where

import Lib
import Data.Char


-- Operators

data Operator = Plus | Minus | Times | Div
    deriving (Show, Eq)

opToChar :: Operator -> Char
opToChar Plus = '+'
opToChar Minus = '-'
opToChar Times = '*'
opToChar Div = ':'

operator:: Char -> Operator
operator c  | c == '+' = Plus
            | c == '-' = Minus
            | c == '*' = Times
            | c == '/' = Div


data Token = TokOp Operator
            | TokIdent String
            | TokNum Int
            | TokSpace
    deriving (Show, Eq)

showContent:: Token -> String
showContent (TokOp op) = opToChar op  
showContent (TokIdent id) = id 
showContent (TokNum num) = show num


tokenizeChar :: Char -> Token
tokenizeChar x
        | elem x "+-*/" = TokOp (operator x)
        | isDigit x = TokNum (digitToInt x)
        | isAlpha x = TokIdent [c] 
        | isSpace x = TokSpace
        | otherwise = error $ "Cannot Tokenize" ++ [x]




data Expression

parse:: [Token] -> Expression
parse = undefined


evaluate:: Expression -> Double
evaluate = undefined



main :: IO ()
main = do
    line <- getLine
    putStrLn line
    main


