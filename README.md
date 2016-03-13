#ipow --- an efficient C++ function for calculating integral power
## Abstract
It is named from "integral power."  This is the C++ function that computs an integral power(the exponent must not be nagative)

## Why does it necessary?
The standard library of C/C++ languages provides the pow() function.  It calculates the power of the arguments.  However, it contains a problem --- its arguments must be all floating-point type.  That is, it is NOT OPTIMIZED FOR COMPUTING INTEGRAL POWER.  Therefore, I implemented an efficient algorithm for it.

## How to use
Just put ipow.hpp into the project directory, include it, and call the function like the following.

```C++
ipow(BASE, EXPONENT)
```

`BASE` must be a numerical type, and `EXPONENT` must be a not-negative integer. (`EXPONENT` can be signed/unsigned int, long, short, and so on)
