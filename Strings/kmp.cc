/*
    KMP - Knuth–Morris–Pratt algorithm
    Implement strstr(a, b): return the first match index where b is a substring of a
*/

#include <bits/stdc++.h>
using namespace std;

void kmp(string& needle, vector<int>& preproc) {
    int l = 0, r = 1;
    while (r < needle.size()) {
        if (needle[l] == needle[r]) {
            preproc[r] = l + 1;
            l++, r++;
        }
        else if (l) {
            l = preproc[l-1];
        }
        else {
            r++;
        }
    }
}

int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();
    vector<int> preproc (n);
    kmp(needle, preproc);

    int i = 0, j = 0;
    while (i < m and j < n) {
        if (haystack[i] == needle[j]) {
            i++, j++;
        }
        else if (j) {
            j = preproc[j-1];
        }
        else {
            i++;
        }
    }
    return j == n ? i - j : -1;
}