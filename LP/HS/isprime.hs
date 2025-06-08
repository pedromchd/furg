primo n = length [x | x <- [1..n], n `mod` x == 0] == 2

main = do
    putStrLn "Digite um numero:"
    n <- readLn
    if primo n
        then putStrLn "É primo"
        else putStrLn "Não é primo"