/**
 * 整数乗ライブラリ(The integral power library/ipow)
 * Copyright © 2017 UCHINO Tatsunori
 * This library is licensed under the zlib license.
 * https://opensource.org/licenses/Zlib
 * However, you can remove this notification only if you use this for closed-source and non-commercial purpose such as competitive programming and homework.
 *
 * This computes x to nth power where n is a not-negative integer.
 */
#include <type_traits>
#include <limits>
#include <stdexcept>

template<typename T, typename I>
#if __cplusplus >= 201402L
constexpr T ipow(const T &base, const I &exp)
#else
T ipow(const T &base, const I &exp)
#endif
{
  constexpr I I_0 = 0;
  static_assert(std::is_integral<I>::value == true, "冪指数は整数型でなければなりません。(The exponent must be an integer.)");
  T ret = (T)1;
  constexpr I maxval = std::numeric_limits<I>::max(); // (0)11111111111....
  constexpr I highestbit = maxval ^ (maxval >> 1);    // (0)10000000000....
  if(std::is_signed<I>::value && exp < I_0) {
      const I&& minus_exp_minus_1 = -(exp + 1);
      for(I mask = highestbit; mask != I_0; mask >>= 1) {
        ret *= ret;
        if((mask & minus_exp_minus_1) != I_0) ret /= base;
    }
    ret /= base;
  } else {
    for(I mask = highestbit; mask != I_0; mask >>= 1) {
        ret *= ret;
        if((mask & exp) != I_0) ret *= base;
    }
  }
  return ret;
}
