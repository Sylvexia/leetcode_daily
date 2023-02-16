// 2013. Detect Squares

#include <bits/stdc++.h>

using namespace std;

class DetectSquares
{
    unordered_map<int, unordered_map<int, int>> points;

public:
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        int x = point[0], y = point[1];
        points[x][y]++;
    }

    int count(vector<int> point)
    {
        int x1 = point[0], y1 = point[1];
        int res = 0;

        for (auto [x3, p] : points)
        {
            for (auto [y3, c] : p)
            {
                if (x1 == x3 or abs(x1 - x3) != abs(y1 - y3))
                    continue;

                res += points[x3][y3] * points[x1][y3] * points[x3][y1];
            }
        }

        return res;
    }
};