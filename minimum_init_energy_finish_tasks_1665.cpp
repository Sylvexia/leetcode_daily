// 1665. Minimum Initial Energy to Finish Tasks

#include <bits/stdc++.h>
#include <algorithm>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution2
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        auto comp = [](vector<int> &a, vector<int> &b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        };
        sort(tasks.begin(), tasks.end(), comp);

        int res = 0;
        int energy = 0;

        for (auto &t : tasks) {
            int actual = t[0];
            int init = t[1];

            if (energy < init) {
                res += (init - energy);
                energy = init;
            }
            energy -= actual;
        }
        return res;
    }
};

class Solution
{
    bool cond(int m, vector<vector<int>> &tasks)
    {
        for (auto &t : tasks) {
            int actual = t[0];
            int thresh = t[1];
            if (m < thresh)
                return false;
            m -= actual;
        }
        return true;
    }

public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        auto comp = [](vector<int> &a, vector<int> &b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        };
        sort(tasks.begin(), tasks.end(), comp);

        int l = 0;
        int r = INT_MAX;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (cond(m, tasks))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};