// 860. Lemonade Change

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0, tens = 0, twenties = 0;
        for (int b : bills) {
            switch (b) {
            case 5: {
                fives++;
                break;
            }
            case 10: {
                if (fives == 0)
                    return false;
                fives--;
                tens++;
                break;
            }
            case 20: {
                if (tens >= 1 and fives >= 1) {
                    tens--;
                    fives--;
                } else if (fives >= 3)
                    fives -= 3;
                else
                    return false;
                twenties++;
            }
            }
        }

        return true;
    }
};