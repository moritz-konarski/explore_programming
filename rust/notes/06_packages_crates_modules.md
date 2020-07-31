# Chapter 7: Managing Growing Projects with Packages, Crates, and Modules

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

- 


\newpage
