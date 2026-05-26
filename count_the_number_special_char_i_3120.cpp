// 3120. Count the Number of Special Characters I

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
    int numberOfSpecialChars(string word)
    {
        unordered_set<char> u_set;
        for (char ch : word)
            u_set.insert(ch);
        
        int res = 0;
        for (auto key : u_set)
            res += (u_set.count(key + 32));
        return res;
    }
};