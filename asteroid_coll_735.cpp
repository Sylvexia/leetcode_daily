// 735. Asteroid Collision

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> to_left, to_right, res;
        for (int a : asteroids)
        {
            if (a > 0)
                to_right.push_back(a);
            else
            {
                while (to_right.size() and -a > to_right.back())
                    to_right.pop_back();
                if (to_right.size() and -a == to_right.back())
                {
                    to_right.pop_back();
                    continue;
                }
                if (to_right.empty())
                    to_left.push_back(a);
            }
        }
        res.insert(res.end(), to_left.begin(), to_left.end());
        res.insert(res.end(), to_right.begin(), to_right.end());
        return res;
    }
};