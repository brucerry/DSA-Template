/*
    pow(x, n) in O(logn) time
*/

#include <bits/stdc++.h>
using namespace std;

double solve(double x, int n) {
    if (n == 0)
        return 1;

    if (n == 1)
        return x;
    
    double res = solve(x * x, n / 2);
    return n & 1 ? res * x : res;
}

double pow(double x, int n) {
    double res = solve(x, abs(n));
    return n < 0 ? 1 / res : res;
}
  
