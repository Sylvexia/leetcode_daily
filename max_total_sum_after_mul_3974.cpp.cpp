// 3974. Maximum Total Sum of K Selected Elements

#include <functional>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maxSum(vector<int> &nums, int k, int mul)
    {
        ranges::sort(nums, greater<long long>());
        long long res = 0;
        for (int i = 0; i < k; i++) {
            long long cur = max((long long) mul * nums[i], (long long) nums[i]);
            res += cur;
            mul--;
        }
        return res;
    }
};