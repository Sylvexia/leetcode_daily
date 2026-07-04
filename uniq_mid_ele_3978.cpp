// 3978. Unique Middle Element

#include <iostream>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool isMiddleElementUnique(vector<int> &nums)
    {
        int mid = nums.size() / 2;
        unordered_map<int, int> u_map;
        for (int n : nums)
            u_map[n]++;
        return u_map[nums[mid]] == 1;
    }
};