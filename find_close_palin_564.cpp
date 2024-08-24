// 564. Find the Closest Palindrome

#include <bits/stdc++.h>
#include <climits>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        if (n.length() == 1)
            return to_string(stol(n) - 1);

        int digits = n.length();
        vector<long> res_vec;
        res_vec.push_back(pow(10, digits - 1) - 1);
        res_vec.push_back(pow(10, digits) + 1);

        int mid_idx = (digits + 1) / 2;
        long prefix = stol(n.substr(0, mid_idx));

        vector<long> prefix_vec = {prefix, prefix + 1, prefix - 1};
        for (long p : prefix_vec) {
            string posfix = to_string(p);
            if (digits % 2 != 0)
                posfix.pop_back();
            reverse(posfix.begin(), posfix.end());
            string res_str = to_string(p) + posfix;
            res_vec.push_back(stol(res_str));
        }

        long n_val = stol(n);
        long min_diff = LONG_MAX;
        long res = LONG_MAX;
        for (long r : res_vec) {
            long diff = abs(r - n_val);
            if (r != n_val and diff < min_diff) {
                min_diff = diff;
                res = r;
            } else if (diff == min_diff)
                res = min(res, r);
        }
        return to_string(res);
    }
};