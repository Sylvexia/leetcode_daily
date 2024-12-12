// 2558. Take Gifts From the Richest Pile

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
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k) {
            auto top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
            k--;
        }
        long long res = 0;
        while (pq.size()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};