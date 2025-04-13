/*
    Recursive version
    pow(x, n, mod) in O(logn) time
    Take mod during the process
*/

#include <bits/stdc++.h>
using namespace std;

long pow(long x, long n, long mod = 1e9+7) {
    if (n == 0)
        return 1;
    auto p = pow(x, n / 2);
    return p * p % mod * (n % 2 ? x : 1) % mod;
}