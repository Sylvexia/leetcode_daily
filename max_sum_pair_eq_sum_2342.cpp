// 2342. Max Sum of a Pair With Equal Sum of Digits

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int getDigitSum(int n)
    {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, priority_queue<int>> u_map;
        for (int n : nums) {
            int digitSum = getDigitSum(n);
            u_map[digitSum].push(n);
        }

        int res = -1;
        for (auto &[digitSum, pq] : u_map) {
            int cur = 0;
            if (pq.size() < 2)
                continue;
            for (int i = 0; i < 2; i++) {
                cur += pq.top();
                pq.pop();
            }
            res = max(res, cur);
        }
        return res;
    }
};