// 2358. Maximum Number of Groups Entering a Competition

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int n = grades.size();
        return (sqrt(1 + 8.0 * n) - 1) / 2;
    }
};

class Solution2
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int n = grades.size();

        int sum = 0;
        int groups = 0;

        for (int i = 1; sum + i <= n; i++) {
            sum += i;
            groups++;
        }
        return groups;
    }
};
