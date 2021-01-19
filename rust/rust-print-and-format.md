# rust-print-and-format

rust print and format usage

--------------------------

- [rust-print-and-format](#rust-print-and-format)
  - [prerequisite](#prerequisite)
  - [desc](#desc)
  - [inst](#inst)
    - [1.](#1)
    - [escape:](#escape)
    - [formatting trait](#formatting-trait)
  - [ref](#ref)
  - [tags](#tags)

## prerequisite

- rust

## desc
rust에서 프린팅 및 포매팅
(from rbe)

## inst

### 1. 

기본적인 출력 방식은 익숙하니 넘어가고, 출력 옵션들은 `"{positioning:formatOption}"` 이런 구조로 되어 있다.
positioning에는 0,1같은 숫자나, 키값을 넣을 수 있다.
formatOption에는 다음과 같이 다양한 옵션이 들어간다:

```
format_string := <text> [ maybe-format <text> ] *
maybe-format := '{' '{' | '}' '}' | <format>
format := '{' [ argument ] [ ':' format_spec ] '}'
argument := integer | identifier

format_spec := [[fill]align][sign]['#']['0'][width]['.' precision][type]
fill := character
align := '<' | '^' | '>'
sign := '+' | '-'
width := count
precision := count | '*'
type := identifier | '?' | ''
count := parameter | integer
parameter := argument '$'
```

precision은 반올림된다.

### escape:
{,}는 각각 {{,}}로 escape한다

### formatting trait

  nothing ⇒ Display
  ? ⇒ Debug
  x? ⇒ Debug with lower-case hexadecimal integers
  X? ⇒ Debug with upper-case hexadecimal integers
  o ⇒ Octal
  x ⇒ LowerHex
  X ⇒ UpperHex
  p ⇒ Pointer
  b ⇒ Binary
  e ⇒ LowerExp
  E ⇒ UpperExp

format_args!는 무슨 역할인지 잘 모르겠다.

```rs

// print using display trait
println!("{}", 1)

// right align print : "     1"
println!("{number:>width$}", number=1, width=6);

// pad left : "000001"
println!("{number:>0width$}", number=1, width=6)

// print using debug trait
println!("{:?}", 1)

// positional parameters
format!("{1} {} {0} {}", 1, 2); // => "2 1 1 2"

```

## ref
- https://doc.rust-lang.org/rust-by-example/hello/print.html
- https://doc.rust-lang.org/std/fmt/

## tags
  \#rust, \#sport, \#tip

--------------------------


 