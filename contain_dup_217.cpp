// 217. Contains Duplicate

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> count;
        for (auto num : nums)
        {
            if (count.count(num))
                return true;
            count.insert(num);
        }
        return false;
    }
};