// 3223. Minimum Length of String After Operations

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumLength(string s)
    {
        array<int, 26> arr;
        fill(arr.begin(), arr.end(), 0);
        for (char c : s)
            arr[c - 'a']++;

        int del = 0;
        for (int i = 0; i < 26; i++) {
            int val = arr[i];
            del += val > 2 ? (val - 1) / 2 * 2 : 0;
        }
        return s.size() - del;
    }
};