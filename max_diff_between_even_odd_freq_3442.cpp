// 3442. Maximum Difference Between Even and Odd Frequency I

#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxDifference(string s)
    {
        unordered_map<char, int> uMap;
        for (char c : s)
            uMap[c]++;

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        for (auto [_, val] : uMap) {
            if (val % 2)
                maxOdd = max(maxOdd, val);
            else
                minEven = min(minEven, val);
        }

        maxOdd = maxOdd == INT_MIN ? 0 : maxOdd;
        minEven = minEven == INT_MAX ? 0 : minEven;
        return maxOdd - minEven;
    }
};