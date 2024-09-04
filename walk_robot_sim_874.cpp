// 874. Walking Robot Simulation

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_set<string> obs_set;
        for (auto obs : obstacles) {
            obs_set.insert(to_string(obs[0]) + "_" + to_string(obs[1]));
        }
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pair<int, int> cur = {0, 0};
        int res = 0;
        int dir_idx = 0;
        for (int c : commands) {
            if (c == -1)
                dir_idx = (dir_idx + 1) % 4;
            else if (c == -2)
                dir_idx = (dir_idx + 3) % 4;
            else {
                for (int step = 0; step < c; step++) {
                    int temp_x = dirs[dir_idx].first + cur.first;
                    int temp_y = dirs[dir_idx].second + cur.second;
                    if (obs_set.find((to_string(temp_x) + "_" +
                                      to_string(temp_y))) != obs_set.end())
                        break;
                    cur.first = temp_x;
                    cur.second = temp_y;
                    res = max(res,
                              cur.first * cur.first + cur.second * cur.second);
                }
            }
        }
        return res;
    }
};