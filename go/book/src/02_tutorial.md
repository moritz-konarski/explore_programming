# Tutorial 

- shows the basic components of Go
- gives an overview of the features of Go

## Hello, World

```go    
    package main

    import "fmt"

    func main() {
        fmt.Println("Hello, World")
    }
```
- run a program using
```bash
    go run hello_world.go
```
- to compile it and keep the executable
```bash
    go build hello_world.go
```
- code is organized into packages, kinda like libraries or modules
- each package begins with a package declaration -- states which package the
file belongs to 
- the Go standard library has over 100 packages for string manipulation,
formatting (like `fmt`)
- `main` is special because it defines a standalone executable, not a labrary
- `func main()` is also the entry point of the program
- `import` tells the compiler which packages are needed for the program
- you must only import packages that are needed, any missing or unnecessary
ones will prevent compilation
- `import` must follow `package`, after that it's fair game for all other stuff
(`func`, `var`, `const`, `type`)
- new lines matter in Go code, they are basically converted to semicolons --
which you can make but don't have to
- Go is very particular about formatting, so use `gofmt` or `go fmt` to format
files correctly

## Command Line Arguments
