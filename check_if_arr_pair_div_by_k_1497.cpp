// 1497. Check If Array Pairs Are Divisible by k

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> u_map;
        for (int n : arr) {
            if (n < 0)
                u_map[(k - (-n % k)) % k]++;
            else
                u_map[n % k]++;
        }

        for (int i = 1; i <= k - 1; i++) {
            if (u_map[i] != u_map[k - i])
                return false;
        }
        return (u_map[0] % 2 == 0);
    }
};