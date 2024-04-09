// 2073. Time Needed to Buy Tickets

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int res = 0;
        int idx = 0;
        while (tickets[k] > 0) {
            if (tickets[idx] > 0) {
                tickets[idx]--;
                res++;
            }
            idx++;
            idx %= tickets.size();
        }

        return res;
    }
};