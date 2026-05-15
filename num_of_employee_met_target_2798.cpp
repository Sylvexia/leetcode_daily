// 2798. Number of Employees Who Met the Target

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int res = 0;
        for (int h : hours)
            res += (h >= target);
        return res;
    }
};