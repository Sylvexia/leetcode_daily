// 2216. Minimum Deletions to Make Array Beautiful

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int res = 0;
        vector<int> vec;
        
        for (int x : nums) {
            vec.push_back(x);

            if (vec.size() >= 2 and vec.size() % 2 == 0 and
                vec[vec.size() - 2] == vec[vec.size() - 1]) {
                vec.pop_back();
                res++;
            }
        }

        if (vec.size() % 2 == 1)
            res++;

        return res;
    }
};