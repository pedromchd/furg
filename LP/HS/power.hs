main = do
    putStrLn "Digite x:"
    x <- readLn
    putStrLn "Digite n:"
    n <- readLn
    print (x^n)