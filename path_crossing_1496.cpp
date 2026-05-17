// 1496. Path Crossing

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    using pii = pair<int, int>;
    string convertStr(pii cur)
    {
        return to_string(cur.first) + "_" + to_string(cur.second);
    }

public:
    bool isPathCrossing(string path)
    {
        pii cur = {0, 0};
        unordered_set<string> u_set;
        u_set.insert(convertStr(cur));
        
        for (char c : path) {
            if (c == 'N')
                cur.first--;
            else if (c == 'S')
                cur.first++;
            else if (c == 'E')
                cur.second++;
            else if (c == 'W')
                cur.second--;
            if (u_set.count(convertStr(cur)))
                return true;
            u_set.insert(convertStr(cur));
        }
        return false;
    }
};