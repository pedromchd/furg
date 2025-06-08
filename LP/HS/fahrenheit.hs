main = do
    putStrLn "Digite a temperatura em Fahrenheit:"
    f <- readLn
    let c = (f - 32) * 5 / 9
    print c