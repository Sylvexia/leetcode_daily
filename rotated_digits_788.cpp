// 788. Rotated Digits

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int rotatedDigits(int n)
    {
        unordered_set<int> rotate_set{2, 5, 6, 9};
        unordered_set<int> banned_set{3, 4, 7};
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int curNum = i;
            bool inRotate = false;
            bool inBan = false;
            while (curNum > 0) {
                int rem = curNum % 10;
                curNum /= 10;

                if (rotate_set.find(rem) != rotate_set.end())
                    inRotate |= true;
                if (banned_set.find(rem) != banned_set.end())
                    inBan |= true;
            }
            if (inRotate and !inBan)
                res++;
        }
        return res;
    }
};