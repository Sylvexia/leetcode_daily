// 1945. Sum of Digits of String After Convert

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int getLucky(string s, int k)
    {
        vector<int> convert_vec;
        for (char ch : s)
            convert_vec.push_back(ch - 'a' + 1);
        int transform = 0;
        for (int n : convert_vec) {
            transform += n / 10 + n % 10;
        }
        if (k == 1)
            return transform;

        int res = 0;
        int local = 0;
        for (int i = k - 1; i > 0; i--) {
            local = 0;
            while (transform > 0) {
                local += transform % 10;
                transform /= 10;
            }
            transform = local;
        }
        res = local;
        return res;
    }
};