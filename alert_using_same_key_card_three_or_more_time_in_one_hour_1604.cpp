// 1604. Alert Using Same Key-Card Three or More Times in a One Hour Period

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int getMinute(string str)
    {
        string hour = str.substr(0, 2);
        string min = str.substr(3, 2);
        return atoi(hour.c_str()) * 60 + atoi(min.c_str());
    }

public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        int n = keyName.size();
        unordered_map<string, vector<int>> u_map;
        for (int i = 0; i < n; i++) {
            u_map[keyName[i]].push_back(getMinute(keyTime[i]));
        }

        unordered_set<string> u_set;
        for (auto &[key, val] : u_map) {
            ranges::sort(val);
            int m = val.size();
            for (int i = 0; i + 2 < m; i++) {
                if (val[i + 2] - val[i] <= 60)
                    u_set.insert(key);
            }
        }

        vector<string> res{u_set.begin(), u_set.end()};
        ranges::sort(res);
        return res;
    }
};