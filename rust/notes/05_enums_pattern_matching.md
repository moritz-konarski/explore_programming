# Enums and Pattern Matching

- enums are enumerations -- types defined by their possible variants
- enums, the `Option` enum, `match` expression, `if let` construct

## Defining an Enum

- used for a known number of different cases, e.g. IPv4 and IPv6
- the enumerated things are mutually exclusive
```rust
    enum IpAddrKind {
        V4,
        V6,
    }
```
- this is now a custom data type

### Enum Values

- instances of an enum can be created like this
```rust
    let four = IpAddrKind::V4;
```
- the variants are namespaced under the enum, functions can accept them
```rust
    fn route(ip_kind: IpAddrKind) {
        ...
    }
```
- now we can say which type something is but we don't have a way to store the
associated data
- the naive approach would be an enum with `IpAddrKind` and `String`, but the
better alternative is just an enum
```rust
    enum IpAddr {
        V4(String),
        V6(String),
    }

    let home = IpAddr::V4(String::from("192.168.1.1"));
```
- enums can also handle tuple cases for the associated data type
```rust
    enum IpAddr {
        V4(u8, u8, u8, u8),
        V6(String),
    }
```
- enums can even hold struct or enum data themselves
```rust
    enum Message {
        Quit,
        Move { x: i32, y: i32 },
        Write(String),
        ChangeColor(i32, i32, i32),
    }
```
- and like structs, methods can be associated with them
```rust
    impl Message {
        fn call(&self) {
            // method body 
        }
    }

    let m = Message::Write(String::from("hello"));
    m.call();
```

### The `Option` Enum and Its Advantages Over Null Values

- `Option` encodes the common scenario where something can be something or
nothing
- with this type the compiler can check if all the cases are handled correctly,
preventing bugs
- Rust does not have `Null` as a conscious feature because if you treat a null
value like it is not-null an error will occur and this is super common
- the concept as a whole is pretty good though, it expresses a currently
invalid value, Rust has the `Option<T>` enum
```rust
    enum Option<T> {
        Some(T),
        None,
    }
```
- this enum is so useful that it is automatically included
- the `<T>` means that `Some(T)` can hold any type, strings, numbers, etc
- if `None` is used we need to explicitly specify the type because it is not
inferrable
```rust
    let absent_num: Option<i32> = None;
```
- the thing that makes `Option<T>` better than `Null` is that the `Option<T>` 
and `T` are different values and `Option<T>` cannot be used like a valid value
- generally speaking `Option<T>` needs to be converted to `<T>` before it can
be used
- accordingly, when a value is not `Option<T>` it can be safely assumed that it
is not `Null`
- the `match` expression takes care of the handling of the valid and invalid
cases

## The `match` Control Flow Operator

- match can handle a ton of different cases and the compiler makes sure that
all possible values are handled
```rust
    enum Coin {
        Penny,
        Nickel,
        Dime,
        Quarter,
    }

    fn value_in_cents(coin: Coin) -> u8 {
        match coin {
            Coin::Penny => 1,
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter => 25,
        }
    }
```
- how it works: `match` followed by any kind of expression and then braces
- then come the match arms: the have a pattern and come code, e.g. the pattern
is `Coin::Penny` and the code is `1`, they are separated by `=>`, the arms are
separated by commas
- the comparisons of the value with the arms occurs in order
- if it matches, the associated code is executed
- the code for each arm is an expression and the result is returned by the
match expression -- multiple commands per arm are possible
```rust
    fn value_in_cents(coin: Coin) -> u8 {
        match coin {
            Coin::Penny => {
                println!("Lucky Penny");
                1
            },
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter => 25,
        }
    }
```

### Patterns that Bind to Values

- match arms can bind to parts of the values that match the pattern -- this is
how data can be extracted from enums, e.g.
```rust
    #[derive(Debug)] // so we can inspect the state in a minute
    enum UsState {
        Alabama,
        Alaska,
        // --snip--
    }

    enum Coin {
        Penny,
        Nickel,
        Dime,
        Quarter(UsState),
    }

    fn value_in_cents(coin: Coin) -> u8 {
        match coin {
            Coin::Penny => 1,
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter(state) => {
                println!("State quarter from {:?}!", state);
                25
            },
        }
    }
```

### Matching with `Option<T>`

- this works the same as in the example above
```rust
    fn plus_one(x: Option<i32>) -> Option<i32> {
        match x {
            None => None,
            Some(i) => Some(i + 1),
        }
    }
```

### Matches Are Exhaustive

- every possible case must be handled, otherwise the program won't compile

### The `_` Placeholder

- the `_` placeholder can be used as a `default` that includes all cases that
are not explicitly specified
```rust
    let some_u8_value = 0u8;
    match some_u8_value {
        1 => println!("one"),
        3 => println!("three"),
        5 => println!("five"),
        7 => println!("seven"),
        _ => (),
    }
```
- `match` can be a bit wordy in case only one case is wanted

## Concise Control Flow with `if let`

- if only one type of result of a match expression is of interest, it can be
verbose
```rust
    let some_u8_value = Some(0u8);
    match some_u8_value {
        Some(3) => println!("three"),
        _ => (),
    }
```
- this can be written in a shorter form
```rust
    if let Some(3) = some_u8_value {
        println!("three");
    }
```
- it works by having `if let <pattern> = <expression> { <code> }`
- `if let` has the disadvantage that it does not have exhaustive checking
- the `if let` statement also accepts an else statement, making these two
pieces of code equivalent
```rust
    let mut count = 0;
    match coin {
        Coin::Quarter(state) => 
            println!("State quarter from {:?}!", state),
        _ => count += 1,
    }
    // is the same as
    let mut count = 0;
    if let Coin::Quarter(state) = coin {
        println!("State quarter from {:?}!", state);
    } else {
        count += 1;
    }
```
