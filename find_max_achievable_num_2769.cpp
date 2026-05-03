// 2769. Find the Maximum Achievable Number

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int theMaximumAchievableX(int num, int t) { return num + t * 2; }
};