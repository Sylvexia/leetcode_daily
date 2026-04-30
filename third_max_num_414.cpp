// 414. Third Maximum Number

#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        unordered_set<int> u_set;
        for (int n : nums)
            u_set.insert(n);

        vector<int> temp;
        for (auto num : u_set)
            temp.push_back(num);

        if (u_set.size() < 3)
            return *max_element(temp.begin(), temp.end());

        nth_element(temp.begin(), temp.begin() + 2, temp.end(), greater<>());
        return temp[2];
    }
};