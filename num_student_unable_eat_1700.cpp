// 1700. Number of Students Unable to Eat Lunch

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int cnt[] = {0, 0};
        for (int s : students)
            cnt[s]++;

        for (int i = 0; i < sandwiches.size(); i++) {
            cnt[sandwiches[i]]--;
            if (cnt[sandwiches[i]] < 0)
                return sandwiches.size() - i;
        }
        return 0;
    }
};