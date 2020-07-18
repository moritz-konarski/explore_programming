 pi_over_four = sum [ fromIntegral ((-1)^(n)) / fromIntegral (2 * n + 1) | n <- [0,1..100000] ]

 pi = pi_over_four * 4

 main = print(Main.pi)
