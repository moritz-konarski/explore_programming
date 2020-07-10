# Enums and Pattern Matching

- enums are enumerations -- types defined by their possible variants
- enums, the `Option` enum, `match` expression, `if let` construct

## Defining an Enum

- used for a known number of different cases, e.g. IPv4 and IPv6
- the enumerated things are mutually exclusive
    ```
    enum IpAddrKind {
        V4,
        V6,
    }
    ```
- this is now a custom data type

### Enum Values

- instances of an enum can be created like this
    ```
    let four = IpAddrKind::V4;
    ```
- the variants are namespaced under the enum, functions can accept them
    ```
    fn route(ip_kind: IpAddrKind) {
        ...
    }
    ```
- now we can say which type something is but we don't have a way to store the
associated data
- the naive approach would be an enum with `IpAddrKind` and `String`, but the
better alternative is just an enum
    ```
    enum IpAddr {
        V4(String),
        V6(String),
    }

    let home = IpAddr::V4(String::from("192.168.1.1"));
    ```
- enums can also handle tuple cases for the associated data type
    ```
    enum IpAddr {
        V4(u8, u8, u8, u8),
        V6(String),
    }
    ```
- enums can even hold struct or enum data themselves
    ```
    enum Message {
        Quit,
        Move { x: i32, y: i32 },
        Write(String),
        ChangeColor(i32, i32, i32),
    }
    ```
- and like structs, methods can be associated with them
    ```
    impl Message {
        fn call(&self) {
            // method body 
        }
    }
    
    let m = Message::Write(String::from("hello"));
    m.call();
    ```

### The `Option` Enum and Its Advantages Over Null Values
