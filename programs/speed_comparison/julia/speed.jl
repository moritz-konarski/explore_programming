function speed_test() 
    pi = 0
    for i = 0:10000000
        pi += (-1.0)^i / (2.0 * i + 1)
    end
    return 4*pi
end

#@time speed_test()
#@time speed_test()
for n = 1:100
    println(@time speed_test())
end
#@time speed_test()