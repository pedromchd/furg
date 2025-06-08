main = do
    putStrLn "Quantos números ímpares?"
    n <- readLn
    print (take n [1,3..])