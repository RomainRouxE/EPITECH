module Evalexpr (compute) where

compute :: (Read a, Fractional a) => String -> a
compute expression = check $ parse $ clean expression

data Operators = Plus
               | Minus
               | Times
               | Over
               deriving (Show, Eq)

data Syntax a = Operator Operators
                | Operand a
                | SubList [Syntax a]


space = [' ', '\t', '\n'] ++ ['(', ')']
number = ['0'..'9'] ++ ['.']
operator = ['+', '-', '*', '/']

-- 3 check

check :: (Fractional a) => [Syntax a] -> a
check (a:(Operator o):rest)
    | o == Plus  = (c + d)
    | o == Minus = (c - d)
    | o == Times = (c * d)
    | o == Over  = (c / d)
    where c = check [a]
          d = check rest
check [Operand n] = n
check [SubList l] = check l


-- 2 parse

parse :: (Read a, Fractional a) => String -> [Syntax a]
parse "" = []
parse expression = element : (parse rest)
                   where (element, rest) = next_element expression

next_element :: (Read a, Fractional a) => String -> (Syntax a, String)
next_element s@(first:_)
    | is_operator first = (to_operator operator, rest_o)
    | is_number first = (to_number number, rest_n)
    where (number, rest_n) = span is_number s
          (operator, rest_o) = span is_operator s

is_operator char = any (==char) operator
is_number char = any (==char) number

to_operator "+" = Operator Plus
to_operator "-" = Operator Minus
to_operator "*" = Operator Times
to_operator "/" = Operator Over
to_number s = Operand (read s)
to_sublist s = SubList $ parse s


-- 1 clean

clean expression = filter not_space expression
                   where not_space char = all (/=char) space