// 1433. Check If a String Can Break Another String

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        ranges::sort(s1);
        ranges::sort(s2);
        bool lte = true, gte = true;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i])
                gte = false;
            if (s1[i] > s2[i])
                lte = false;
        }
        return gte | lte;
    }
};