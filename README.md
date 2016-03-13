#ipow(数値の非負整数乗を計算する関数)
##なぜこれが必要なのか
C・C++の標準ライブラリには数値のべき乗を計算する`pow()`関数があるのですが、これは指数でさえも浮動小数点型を引数に取るため、整数乗に最適化されていません。そのため、効率よく整数乗を計算する関数を実装する必要がありました。そこで、これを作成し、せっかくなので公開することとしました。

##使い方
`ipow.hpp`を適当なディレクトリに置き、`#include`文でインクルードし、`pow()`関数と同様に次のように呼び出します。

```C++
ipow(底, 指数)
```

`底`は数値ならなんでも構いませんが、`指数`は非負整数(型の符号の有無は不問、また`int`でも`long`でも`short`でもなんでもOK)である必要があります。

## ライセンス
zlibライセンス(一部用途限定の特例付き; ソースをご覧ください)

#ipow --- an efficient C++ function for calculating integral power
## Abstract
It is named from "integral power."  This is the C++ function that computs an integral power(the exponent must not be nagative)

## Why does it necessary?
The standard library of C/C++ languages provides the `pow()` function.  It calculates the power of the arguments.  However, it contains a problem --- its arguments must be all floating-point type.  That is, it is NOT OPTIMIZED FOR COMPUTING INTEGRAL POWER.  Therefore, I implemented an efficient algorithm for it.

## How to use
Just put `ipow.hpp` into the project directory, include it, and call the function like the following.

```C++
ipow(BASE, EXPONENT)
```

`BASE` must be a numerical type, and `EXPONENT` must be a not-negative integer. (`EXPONENT` can be signed/unsigned int, long, short, and so on)

## License
The zlib license with exception (for some specific purposes)
