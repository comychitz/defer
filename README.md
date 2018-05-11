#defer++
A C++ utility to defer function calls, inspired by Go's defer keyword.

## background
The Go programming language (which I've recently taken on learning) has a
convenient `defer` keyword that allows any function's execution to be deferred
until the surrounding function returns. Allowing the executing to be deferred
benefits developers by allowing less code needed to be written while encouraging
cleaner code flow. An example usage has been shown below. 

```go
func readFile(filePath string) {
    file, err := os.Open(filePath)
    if err != nil {
        fmt.Println("Problems opening file")
        return -1
    }
    defer file.Close() // defer closing the file we opened

    for /* each line in the file */ {
        if /* stop condition */ {
            return 1
        }
    }
    return 0
}
```

If `defer` wasn't available, we would have to insert `file.Close()` prior to
returning at the stop condition and at the end of the function.  The use of
defer prevents the usage of goto-like statements (which just creates spaghetti
code) and allows users to return whenever they'd like in their functions.

## example
Let's look at the same example but in C++ and using the `Defer` template class.

```c++
int readFile(const std::string &filePath) {
    int f = open(filePath.c_str(), 0);
    if(f < 0) {
        printf("Problems opening file\n");
        return -1;
    }
    Defer<int (&)(int)> d(close, f);

    for(/* each line in the file */) {
        if(/* stop condition */) {
            return 1;
        }
    }
    return 0;
}
```

## differences
This C++ defer utility has some differences with Go's defer keyword. First off,
scope matters(!). Since this implementation creates an object of template class
type `Defer`, the function is executed when the object goes out of scope. This
can be advantagous in some uses. Secondly, when the statement with `defer` is
read by the compiler in Go, the arguments are evaluated immediately, but the
function is not executed. In the case for `Defer`, the arguments are not
evaluated until the `Defer` object is being executed (i.e. object is being
destroyed because it is going out of scope). Lastly, a small difference, is that
`Defer` currently only supports a limited number of arguments (but nothing is
stopping you from adding more!).

## todo
* Add support for deferring member functions

