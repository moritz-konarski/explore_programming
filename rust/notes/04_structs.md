# Chapter 5: Using Structs to Structure Related Data

- a struct is a custom data type that packages multiple related values and
makes them a meaningful group
- `struct` is like an objects data attributes
- how do structs and tuples differ, usages, function use
- structs and enums are the heart of Rust's way of creating new types

## Defining and Instantiating Structs

- the data in a struct can be of different types
- each piece of data is named to make things clear
- data is entered in fields whose name and type are specified
```
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}
```
- an instance of the struct needs to be created by giving values for the fields
- the instance is created with the fields in `key: value` pairs, or just values
if the order is the same as in the definition
```
let user1 = User {
    email: String::from("someone@example.com"),
    username: String::from("somename"),
    active: true,
    sign_in_count: 1,
};
```
- to access and to change (if struct is mut) the dot notation is used
```
let name = user.name;

user1.email = String::from("changed@example.com");
```
- functions can return structs
```
fn build_user(email: String, username: String) -> User {
    User {
        email: email,
        username: username,
        active: true,
        sign_in_count: 1,
    }
}
```
- repeating `username` and `email` every time is tedious

### Using the Field Init Shorthand when Variables and Fields Have the Same Name

- we can rewrite the function above to make it shorter
```
fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}
```

### Creating Instances From Other Instances With Struct Update Syntax

- often one wants to copy parts of an existing struct and change some values
- the struct update syntax makes is short, `..` implies that the other fields
should be takes from the specified instance
```
let user2 = User {
    email: String::from("newmail"),
    username: String::from("newuser"),
    ..user1
};
```

### Using Tuple Structs without Name dFiels to Create Different Types

- tuple structs are structs that look similar to tuples
- they are for cases where the struct naming is useful but naming each part of
the struct is superflous
```
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

let origin = Point(0, 0, 0);
```
- Color and Point are different types even though they store the same kind of
data
- they can otherwise be treated like tuples

### Unit-Like Structs Without Any Fields

- one can define dstruct that do not have any fields
- they are called unit-like structs because they are similar to the unit type
- they can be useful in situation where a type is supposed to have a trait but
that type should not store any data -- sounds like an attribute

### Ownership of Struct Data

- a struct own all of its data if the data types are not owned by something
else
- using string slices is not possible without the use of lifetimes

## An Example Program Using Structs

- to understand the use of structs we'll write a program that finds the area of
a rectangle
- starting with a program that only uses variables and then refactoring stuff
until there are only structs left
```
fn main() {
    let width1 = 30;
    let height1 = 50;

    println!("The area of the rectangle is {} square pixels", 
        area(width1, height1));
}

fn area(width: u32, height: u32) -> u32 {
    width * height
}
```
- while it works, the parameters of `area()` don't have an obvious connection
- the previously discussed tuple type could be useful here
```
fn main() {
    let rect = (30, 50);

    println!("The area of the rectangle is {} square pixels", 
        area(rect));
}

fn area(dimensions: (u32, u32)) -> u32 {
    dimensions.0 * dimensions.1
}
```
- this version is both more and less clear
- the calls are shorter but the calculations are less clear; the meaning of the
data is not clear
```
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect = Rectangle {width: 30, height: 50};

    println!("The area of the rectangle is {} square pixels", 
        area(&rect));
}

fn area(rectangle: &Rectangle) -> u32 {
    rectangle.height * rectangle.width
}
```
- this version of the code is much clearer and more understandable

### Adding Useful Functionality with Derived Traits

- it would be nice to be able to print and instance of `Rectangle` and see the
values of all of its fields
- standard printing does not work because it is not implemented
- the `{:?}` syntax is from Debug and it has to be opted in by putting the
below code before the struct definition
```
#[derive(Debug)]
```
- we see `rect1 is Rectangle { width: 30, height: 50 }`, when we use `{:#?}`
the output is
```
rect1 is Rectangle {
    width: 30,
    height: 50
}
```
- for more types and traits and behaviors we can derive see Appendix C
- it would be useful to be able to tie the `area` function to the `Rectangle`
type so that it turns into a _method_ of the type

## Method Syntax

- methods are similar to functions, just that they are defined in the context
of a struct, enum, or trait object and their first parameter is always self
- `self` represents the instance of the struct the method is being called on

### Defining Methods

- changing the area function yields the following result
```
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}
```
- `impl` means implementation and starts the context of Rectangle
- the first argument of a method is `&self` followed by all necessary arguments
- self in this case is immuatbly borrowed, but it can also be mutably borrowed
or owned
- using the `impl` block makes assessing the features of Rectangle simple
because all of the functionality is in one place
- Rust does not use `->` because it uses automatic referencing and
dereferencing which is possible because the `self` signature makes it clear
which one is needed so the code can be cleaner and Rust takes care of the rest

### Methods with More Parameters

- new method that checks if one rectangle can fit completely into another one
```
fn can_hold(&self, other: &Rectangle) -> bool {
    self.width > other.width && self.height > other.height
}
```

### Associated Functions

- associated functions are functions defined in `impl` that _don't_ take self
a parameter
- those functions are associated with the struct, hence the name, see
`String::from`
- associated functions can be used as constructors that return a new instance
of the struct
```
fn build_square(side_length: u32) -> Rectangle {
    Rectangle {width: side_length, height: side_length}
}
```

### Multiple `impl` Blocks

- multiple blocks can be used even if there is no real reason to

## Summary

- structs let you create custom types that are meaningful for your code
\newpage
