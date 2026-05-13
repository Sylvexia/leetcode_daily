// 1464. Maximum Product of Two Elements in an Array

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
    int maxProduct(vector<int> &nums)
    {
        priority_queue<int, vector<int>, less<int>> pq;
        for (int n : nums)
            pq.push(n);

        int one = pq.top();
        pq.pop();
        int two = pq.top();
        return (one - 1) * (two - 1);
    }
};