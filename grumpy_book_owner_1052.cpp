// 1052. Grumpy Bookstore Owner

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int base = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (!grumpy[i]) {
                base += customers[i];
                customers[i] = 0;
            }
        }
        int acquire = 0, sum = 0;
        for (int i = 0, j = 0; j < customers.size(); j++) {
            sum += customers[j];
            if (j - i == minutes)
                sum -= customers[i++];
            acquire = max(acquire, sum);
        }
        return base + acquire;
    }
};