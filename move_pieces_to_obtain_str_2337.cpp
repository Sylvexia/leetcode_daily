// 2337. Move Pieces to Obtain a String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canChange(string start, string target)
    {
        int i = 0, j = 0;
        int n = start.size();
        for (; i < n or j < n; i++, j++) {
            while (i < n and start[i] == '_')
                i++;
            while (j < n and target[j] == '_')
                j++;
            if (i == n or j == n or start[i] != target[j] or
                (start[i] == 'L' and i < j) or (start[i] == 'R' and i > j))
                break;
        }
        return i == n and j == n;
    }
};