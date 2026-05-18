// 3551. Minimum Swaps to Sort by Digit Sum

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

int getDigitSum(int n)
{
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        auto comp = [](int a, int b) {
            int ra = getDigitSum(a);
            int rb = getDigitSum(b);
            if (ra == rb)
                return a < b;
            return ra < rb;
        };

        vector<int> sorted = nums;
        ranges::sort(nums, comp);

        int n = nums.size();
        unordered_map<int, int> getIdx;
        for (int i = 0; i < n; i++)
            getIdx[sorted[i]] = i;

        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            int correctPos = getIdx[nums[i]];;

            if (correctPos == i)
                continue;

            int cur = i;
            int cycle = 0;
            while (!visited[cur]) {
                visited[cur] = true;
                cur = getIdx[nums[cur]];
                cycle++;
            }
            res += cycle - 1;
        }
        return res;
    }
};