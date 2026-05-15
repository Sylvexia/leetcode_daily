// 3492. Maximum Containers on a Ship

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxContainers(int n, int w, int maxWeight)
    {
        return min(n * n, maxWeight / w);
    }
};