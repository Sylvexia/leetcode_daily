// 3760. Maximum Substrings With Distinct Start

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int maxDistinct(string s)
    {
        unordered_set<char> u_set{s.begin(), s.end()};
        return u_set.size();
    }
};