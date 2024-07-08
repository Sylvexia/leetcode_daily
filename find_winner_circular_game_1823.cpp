// 1823. Find the Winner of the Circular Game

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        deque<int> dq;
        for (int i = 1; i <= n; i++)
            dq.push_back(i);

        while (dq.size() > 1) {
            for (int j = 0; j < k; j++) {
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
            }
            dq.pop_back();
        }
        return dq.front();
    }
};