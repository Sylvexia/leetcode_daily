// 974. Subarray Sums Divisible by K

#include <bits/stdc++.h>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> sum_mod(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            int sum = sum_mod[i] + nums[i];
            if (sum < 0)
                sum = k - ((-sum) % k);
            sum_mod[i + 1] = sum % k;
        }

        vector<int> count(k);
        int res = 0;
        for (int s : sum_mod) {
            res += count[s]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> data = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int res = sol.subarraysDivByK(data, k);
    cout << res;
}