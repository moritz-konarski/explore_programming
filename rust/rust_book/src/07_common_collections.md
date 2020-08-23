# Common Collections

- the standard library includes many useful data structures (_collections_)
- collections can contain multiple values while most data structures only
represent on specific value
- collections are stored on the heap and their size does not need to be know at
compile time, they can also dynamically grow
- this chapter will look at 
    - _vector_: store a variable number of values in a kind of array
    - _string_: collection of characters
    - _hash map_: allows the association of a value with a particular key;
    particular implementation of a _map_

## Storing Lists of Values with Vectors

- first collection type looked at is `Vec<T>` -- a vector
- stores more than one value in one data structure next to each other in memory
- can only store values of the same type
- they are useful for a list of items

### Creating a New Vector

- a new vector is created with the new function
```rust
    let v: Vec<i32> = Vec::new();
```
- the type annotation is needed because no data is being inserted into the
vector (can't be inferred) but its type needs to known
- to create a vector with values and type inference, the `vec!` macro is
provided
```rust
    let v = vec![1, 2, 3];
```

### Updating a Vector

- to add elements to a vector, use the `push` method
```rust
    let mut v = Vec::new();

    v.push(2);
    v.push(2222);
```

### Dropping a Vector Drops Its Elements

- like any other struct, a vector is freed when it goes out of scope
```rust
    {
        let v = vec![1, 2, 3];

        // use v
    }   // v goes out of scope and is freed
```
- this can become complicated when references to elements of the vector are
introduced

### Reading Elements of Vectors

- there are two ways to read the values stored in a vector: indexing or the 
`get` method
```rust
    let v = vec![1, 2, 3];

    let third: &i32 = &v[2];    // get a reference to the third element

    match v.get(2) {
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element"),
    }
```
- vectors are indexed starting from `0`
- using `&v` and `[]` gives a reference, using `get` gives `Option<&T>`
- there are two ways to do this because you should have the choice of how the
program reacts when an index is out of bounds
- the reference and brackets method will crash if the index is too large -- use
this if an access out of bounds should never happen
- the get method will not panic and only return none -- use this if
occasionally an element out of bounds might be accessed
- if the obtained reference is valid the borrow checker will enforce the
guidelines from chapter 4 of the rust book
- even if an immutable reference exists to a part of the vector that should
remain unaffected by a modifying action it will not work

### Iterating over the Values in a Vector

- for a loop of immutable references
```rust
    let v = vec![100, 32, 57];
    for i in &v {
        println!("{}", i);
    }
```
- there can also be a loop over all elements in a mutable fashion
```rust
    let mut v = vec![100, 32, 57];
    for i in &mut v {
        *i += 50;
    }
```
- here the de-reference operator `*` needs to be used

### Using an Enum to Store Multiple Types

- because vectors can only store one type of data, there is a trick using enums
that allows multiple values to be stored
- thus the vectors takes one type of enum but the enum variants have different
value types
```rust
    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String),
    }

    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.12),
    ];
```
- Rust needs to know what types will be in the vector at compile time because
it needs to know how much memory is require to hold it
- because vectors are explicit about what kind of values a vector can hold
errors caused by different types being incompatible with operations are
eliminated
- another useful method is the `pop` method that returns the last item in the
vector
