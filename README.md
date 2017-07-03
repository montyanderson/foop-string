# foop-string
String library for the [foop](https://github.com/montyanderson/foop) programming framework.

``` C
string_t *string = new(String);
```

### void $(str)->print()

Prints the string.

``` C
$(str)->print();
```

```
Hello, World!
```

### void $(str)->append(char \*str)

Append a C-style string.

``` C
$(str)->append("Hello, World!");
$(str)->print();
```
