// 2551. Put Marbles in Bags

#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        priority_queue<int, vector<int>, greater<int>> min_q;
        priority_queue<int, vector<int>, less<int>> max_q;
        for (int i = 0; i < n - 1; i++) {
            int curSum = weights[i] + weights[i + 1];
            min_q.push(curSum);
            max_q.push(curSum);
        }

        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            maxSum += max_q.top();
            max_q.pop();
            minSum += min_q.top();
            min_q.pop();
        }
        return maxSum - minSum;
    }
};