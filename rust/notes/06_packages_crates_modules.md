# Projects with Packages, Crates, and Modules

- with large projects organization becomes super important to stay on top of
things
- until now we've written programs in one module in one file
- later it can be split into multiple modules and multiple files
- a package can contain multiple binary crates and optionally one library crate
- large packages can have parts extracted into separate crates that become
external dependencies
- public interfaces to code make it simpler to use other code and keep the
implementation hidden
- scope management is another important aspect, one needs to manage how to keep
things organized and working
- part of Rust's module system are:
    - Packages: Cargo feature to build, test, share crates
    - Crates: three of modules producing a library or executable
    - Modules and use: let you control the organization, scope, and privacy of
    paths
    - Paths: ways of naming items (structs, functions, modules)

## Packages and Crates

- crate: binary or library
- crate root: source file rustc starts from and that makes up the root module
of the crate
- package: one or more crates that provide functionality, contains a Cargo.toml
file describing how to build them
- a package must contain one or zero library crates, it must contain at least
one binary crate or more
- `cargo new` creates a package, `src/main.rs` is the crate root or a binary
crate
- if there is a file called `src/lib.rs` it's the crate root of a library crate
- if a package has both, it also works
- if there are more binary files, they reside in `src/bin` -- each will be
a binary crate
- a crate groups related functionality together so its easy to access, `rand`
from the first program is an example of that
- keeping scopes clear is important so conflicts are avoided -- namespacing

## Defining Modules to Control Scope and Privacy

- modules allow the organization of code into groups for readability and reuse
- they also control the privacy of items -- whether it is available to the
outside (_public_) or a hidden implementation detail (_private_)
- the restaurant example will have empty function so the focus is on the
organization of the code
- nested modules can be used to express real life organizations
```rust
    mod front_of_house {
        mod hosting {
            fn add_to_waitlist() {}

            fn seat_at_table() {}
        }

        mod serving {
            fn take_order() {}

            fn serve_order() {}

            fn take_payment() {}
        }
    }
```
- modules are defined using the `mod` keyword and specify its name, then curly
brackets
- modules can hold other things such as structs, enums, constants, traits
- they group together related definitions -- making it simpler to use
- the `src/lib.rs` file is the crate root because it is at the root
```
    crate
    └── front_of_house
        ├── hosting
        |   │
        |   ├── add_to_waitlist
        |   │
        |   └── seat_at_table
        └── serving
            ├── take_order
            ├── serve_order
            └── take_payment
```
- modules nest in each other, some of them are _siblings_ to each other,
modules are _children_ of others or _parents_ of others

## Paths for Referring to an Item in the Module Tree

- paths are used to tell Rust where to find items -- just like a filesystem
- to call a function, its path needs to be known
    - _absolute path_: starts from the crate root with the crate name or
    a literal crate
    - _relative path_: starts from the current module and uses `self`, `super`,
    or an identifier in the current module
- paths are followed by one or more identifiers separated by `::`
- now we add a public function to our library
```rust
    mod front_of_house {
        mod hosting {
            fn add_to_waitlist() {}
        }
    }
    pub fn eat_at_restaurant() {
        // Absolute path
        crate::front_of_house::hosting::add_to_waitlist();
        
        // Relative path
        front_of_house::hosting::add_to_waitlist();
    }
```
- this code won't work because it is using the `hosting` module in a
function but the module is not public -- it is hidden from the function
- the absolute path starts at crate because it is the root
- the relative path takes advantage of the fact that `front_of_house` is on the
same level as itself
- which naming convention to use is up the design plans but absolute paths can
be safer
- to make things private, they are put into modules -- all items are private by
default
- parent module items can't use child modules' items but child modules can use
parent modules' items -- basically normal inheritance
- using `pub` on inner implementations makes them visible to parent modules

### Exposing Paths with the `pub` Keyword

- to fix the previous listing we need to make `hosting` public to expose it to
its parent modules
- even this does not do the trick because `add_to_waitlist` is still private
and thus not accessible
- making its module private did not expose the function in it
- after making the function public too the code compiles
```rust
    mod front_of_house {
        pub mod hosting {
            pub fn add_to_waitlist() {}
        }
    }
    pub fn eat_at_restaurant() {
        // Absolute path
        crate::front_of_house::hosting::add_to_waitlist();
        
        // Relative path
        front_of_house::hosting::add_to_waitlist();
    }
```
- siblings have automatic visibility of each other -- anything below them in
the tree is private, anything above is visible

### Starting Relative Paths with `super`

- `super` at the start of a path means that it begins at the parent module
- this allows the access of an item that is one level above the current one
```rust
    fn serve_order() {}

    mod back_of_house {
        fn fix_incorrect_order() {
            cook_order();
            super::serve_order();
        }

        fn cook_order() {}
    }
```

### Making Structs and Enums Public

- `pub` has the same effect on enums and structs that is has on functions
- using pub before a struct definition, the struct will be public but its
fields will not be -- each of the fields can be either public or private
```rust
    mod back_of_house {
        pub struct Breakfast {
            pub toast: String,
            seasonal_fruit: String,
        }

        impl Breakfast {
            pub fn summer(toast: &str) -> Breakfast {
                Breakfast {
                    toast: String::from(toast),
                    seasonal_fruit: String::from("peaches"),
                }
            }
        }
    }

    pub fn eat_at_restaurant() {
        // Order a breakfast in the summer with Rye toast
        let mut meal = back_of_house::Breakfast::summer("Rye");
        // Change our mind about what bread we'd like
        meal.toast = String::from("Wheat");
        println!("I'd like {} toast please", meal.toast);
        // The next line won't compile if we uncomment it; we're not allowed
        // to see or modify the seasonal fruit that comes with the meal
        // meal.seasonal_fruit = String::from("blueberries");
    }
```
- if a struct has a private field, it needs a public function to create it
because otherwise the private field could not be set
- if an `enum` is made public, all of its elements are made public
```rust
    mod back_of_house {
        pub enum Appetizer {
            Soup,
            Salad,
        }
    }

    pub fn eat_at_restaurant() {
        let order1 = back_of_house::Appetizer::Soup;
        let order2 = back_of_house::Appetizer::Salad;
    }
```

## Bringing Paths into Scope with the `use` Keyword

- all the paths we have used thus far have been long and cumbersome, they can
be shortened with the help of the `use` keyword
- bringing a path into scope will substantially shorten the function calls
```rust
    mod front_of_house {
        pub mod hosting {
            pub fn add_to_waitlist() {}
        }
    }

    use crate::front_of_house::hosting;

    pub fn eat_at_restaurant() {
        hosting::add_to_waitlist();
        hosting::add_to_waitlist();
        hosting::add_to_waitlist();
    }
```
- items can also be brought into scope with a relative path
```rust
    mod front_of_house {
        pub mod hosting {
            pub fn add_to_waitlist() {}
        }
    }

    use front_of_house::hosting;

    pub fn eat_at_restaurant() {
        hosting::add_to_waitlist();
        hosting::add_to_waitlist();
        hosting::add_to_waitlist();
    }
```

### Creating Idiomatic `use` Paths

- the idiomatic way to bring functions into scope is to bring their parent
modules into scope and then call them with their parent modules attached
- this makes it clear that the function is not defined locally
- when using enums or structs on the other hand, the full path is specified and
only their name is used
- the only hard line is bringing two items with the same name into scope, in
that case the parent module must be specified
```rust
    use std::fmt;
    use std::io;

    fn function1() -> fmt::Result {
        // --snip--
    }

    fn function2() -> io::Result<()> {
        // --snip--
    }
```
- it is also not allowed to fully import two modules with the same names for
the same reason

### Providing New Names with the `as` Keyword

- another solution to the problem above is to give the item a new local name
```rust
    use std::fmt::Result;
    use std::io::Result as IoResult;

    fn function1() -> Result {
        // --snip--
    }

    fn function2() -> IoResult<()> {
        // --snip--
    }
```
- both solutions are idiomatic so it depends on the programmer

### Re-exporting Names with `pub use`

- when a name is brought into scope with `use` it is private
- sometimes it is useful to import code into a program and at the same time
make it available to others calling our code -- this is called re-exporting
```rust
    mod front_of_house {
        pub mod hosting {
            pub fn add_to_waitlist() {}
        }
    }

    pub use crate::front_of_house::hosting;

    pub fn eat_at_restaurant() {
        hosting::add_to_waitlist();
        hosting::add_to_waitlist();
        hosting::add_to_waitlist();
    }
```
- the above code allows external code to also call the `hosting` module and the
`add_to_waitlist` function
- this allows the library to behave differently and in an optimized way --
depending on what is necessary

### Using External Packages

- in Chapter 2 of the rust book we used the `rand` crate
```rust
    [dependencies]
    rand = "0.5.5"
```
- then we used it in our program
```rust
    use rand::Rng();

    fn main () {
        let secret_number = rand::thread_rng().gen_range(1, 101);
    }
```
- <https://crates.io> hosts many useful crates and using them is always the
same
    1. list them in the packages _Cargo.toml_ file
    2. use `use` to bring them into scope
- the standard library `std` is also external to our crate but it is shipped
with Rust
- standard library functions still need to be brought into scope

### Using Nested Paths to Clean Up Large `use` Lists

- if multiple items defined in the same package or module are used, the `use`
statements can become quite long
- instead, we specify the common parts of the path and then list the individual
items in braces
```rust
    use std::{cmp::Ordering, io};
```
- the longer the shared path, the better the nested paths look

### The Glob Operator

- if all public items in a path are supposed to be brought into scope the glob
operator can be used
```rust
    use std::collections::*;
```
- this can be an issue because you don't know where certain names come from or
which are even in your program

## Separating Modules into Different Files

- when projects become too large, one might want to split them into multiple
files
- to do this, create a file named `file.rs` in the `src` directory
- to be able to use the files contents, use 
```rust
    mod file;
```

in the file

- this makes `file.rs` available
- the names of the modules and the files must match
- one step further is to create a directory called `./file/` and in `file.rs`
write
```rust
    mod sub_file;
```
- now we can create a file `./file/sub_file.rs` that will be loaded as a child
of the `file` module
