// 2751. Robot Collisions

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,
                                      vector<int> &healths,
                                      string directions)
    {
        int n = positions.size();
        vector<int> index(n), stack, res;
        for (int i = 0; i < n; i++)
            index[i] = i;

        auto comp = [&](int a, int b) { return positions[a] < positions[b]; };
        sort(index.begin(), index.end(), comp);

        for (int i : index) {
            if (directions[i] == 'R') {
                stack.push_back(i);
                continue;
            }
            while (stack.size() and healths[i] > 0) {
                if (healths[stack.back()] < healths[i]) {
                    healths[stack.back()] = 0;
                    stack.pop_back();
                    healths[i]--;
                } else if (healths[stack.back()] > healths[i]) {
                    healths[stack.back()]--;
                    healths[i] = 0;
                } else {
                    healths[stack.back()] = 0;
                    stack.pop_back();
                    healths[i] = 0;
                }
            }
        }

        for (int h : healths) {
            if (h > 0)
                res.push_back(h);
        }
        return res;
    }
};