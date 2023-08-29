// 2483. Minimum Penalty for a Shop

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int min_pen = 0;
        int cur_pen = 0;
        int min_hour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y')
                cur_pen += 1;
        }

        min_pen = cur_pen;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y')
                cur_pen -= 1;
            else
                cur_pen += 1;

            if (cur_pen < min_pen) {
                min_pen = cur_pen;
                min_hour = i + 1;
            }
        }

        return min_hour;
    }
};