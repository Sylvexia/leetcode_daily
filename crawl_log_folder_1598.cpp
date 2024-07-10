// 1598. Crawler Log Folder

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int level = 0;
        for (auto &s : logs) {
            if (s == "../")
                level = max(0, level - 1);
            else if (s == "./") {
            } else
                level += 1;
        }
        return level;
    }
};