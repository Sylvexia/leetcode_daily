// 1004. Max Consecutive Ones III

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = -1, r = 0, res = 0;
        queue<int> q;

        for (; r < nums.size(); r++) {
            if (nums[r] == 0) {
                q.push(r);
                if (q.size() > k) {
                    l = q.front();
                    q.pop();
                }
            }
            res = max(res, r - l);
        }
        return res;
    }
};