// 075. Maximize Happiness of Selected Children

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long res = 0;

        priority_queue<int, vector<int>, less<int>> pq;

        for (int h : happiness)
            pq.push(h);

        for (int i = 0; i < k; i++) {
            int top = pq.top();
            top -= i;
            if (top <= 0)
                break;
            pq.pop();
            res += top;
        }

        return res;
    }
};