// 149. Max Points on a Line

#include <bits/stdc++.h>

using namespace std;

struct custom_hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return p.first ^ p.second * 3;
    }
};

class Solution
{
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    int maxPoints(vector<vector<int>> &points)
    {
        int res{1};
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<pair<int, int>, int, custom_hash> u_count;
            int dup{1};
            for (int j = i + 1; j < points.size(); j++)
            {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    dup++;
                else
                {
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    int g = gcd(dx, dy);
                    u_count[{{dx / g}, {dy / g}}]++;
                }
                res = max(res, dup);
                for (auto &[key, value] : u_count)
                {
                    res = max(res, value + dup);
                }
            }
        }
        return res;
    }
};