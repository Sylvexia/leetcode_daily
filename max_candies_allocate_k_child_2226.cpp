// 2226. Maximum Candies Allocated to K Children

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        auto feasible = [&](long long m) {
            long long piles = 0;
            for (auto c : candies) {
                piles += c / m;
            }
            return piles >= k;
        };

        int yes = 0;
        int no = *max_element(candies.begin(), candies.end()) + 1;

        while (abs(yes - no) > 1) {
            long long m = (yes + no) / 2;
            if (feasible(m))
                yes = m;
            else
                no = m;
        }
        return yes;
    }
};