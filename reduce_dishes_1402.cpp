// 1402. Reducing Dishes

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSatisfaction(vector<int> &s)
    {
        sort(s.begin(), s.end());

        int res = 0;
        for (int start = s.size() - 1; start < s.size(); start--)
        {
            int sum = 0;
            for (int i = start; i < s.size(); i++)
                sum += s[i] * (i - start + 1);
            res = max(res, sum);
        }

        return res;
    }
};