# type annotations
# these are useful because the tell the function how to
# behave in certain cases -- make is simpler for the compiler
# to know whats going on

function test1(x::Int)
    println("$x is an Int")
end

function test1(x::Float64) 
    println("$x is a Float")
end

function test1(x)
    println("$x is neither float nor int")
end
