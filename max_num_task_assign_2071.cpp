// 2071. Maximum Number of Tasks You Can Assign

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks,
                      vector<int> &workers,
                      int pills,
                      int strength)
    {
        int yes = 0;
        int no = min(tasks.size(), workers.size()) + 1;
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int m) {
            int used = 0;
            multiset<int> free(workers.end() - m, workers.end());
            for (int i = m - 1; i >= 0; i--) {
                auto it = prev(free.end());  // greatest
                if (*it < tasks[i]) {
                    it = free.lower_bound(tasks[i] - strength);
                    if (it == free.end())
                        return false;
                    used++;
                    if (used > pills)
                        return false;
                }
                free.erase(it);
            }

            return true;
        };

        while (abs(yes - no) > 1) {
            int m = (yes + no) / 2;
            if (check(m))
                yes = m;
            else
                no = m;
        }
        return yes;
    }
};