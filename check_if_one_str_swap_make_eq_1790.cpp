// 1790. Check if One String Swap Can Make Strings Equal

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> diffIdx;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                diffIdx.push_back(i);
        }

        if (diffIdx.size() == 0)
            return true;
        
        if (diffIdx.size() == 2)
            return s1[diffIdx[0]] == s2[diffIdx[1]] and
                   s1[diffIdx[1]] == s2[diffIdx[0]];

        return false;
    }
};