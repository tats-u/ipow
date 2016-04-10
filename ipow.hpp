/**
 * 整数乗ライブラリ(The integral power library/ipow)
 * Copyright © 2016 UCHINO Tatsunori
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
T ipow(const T &base, const I &exp) {
  static constexpr I I_0 = 0;
  static_assert(std::is_integral<I>::value == true, "冪指数は整数型でなければなりません。(The exponent must be an integer.)");
  if(exp < I_0) throw std::domain_error("負の冪指数が与えられました。(The negative exponent is not acceptable.)");
  T ret = (T)1;
  static constexpr I maxval = std::numeric_limits<I>::max(); // (0)11111111111....
  static constexpr I highestbit = maxval ^ (maxval >> 1);    // (0)10000000000....
  for(I mask = highestbit; mask != I_0; mask >>= 1) {
    ret *= ret;
    if((mask & exp) != I_0) ret *= base;
  }
  return ret;
}
