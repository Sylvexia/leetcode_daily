// 1346. Check If N and Its Double Exist

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> u_set;
        int zeros = 0;
        for (auto ele : arr)
            if (ele == 0)
                zeros++;
            else
                u_set.insert(ele * 2);

        for (auto ele : arr) {
            if (u_set.count(ele))
                return true;
        }
        return zeros > 1;
    }
};