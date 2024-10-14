// 2530. Maximal Score After Applying K Operations

#include <functional>
#include <queue>
#include "bits/stdc++.h"

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, less<>> pq;
        for (int n : nums)
            pq.push(n);

        long long res = 0;
        while (k > 0) {
            int top = pq.top();
            pq.pop();
            res += top;
            pq.push(top / 3 + (top % 3 != 0));
            k--;
        }
        return res;
    }
};