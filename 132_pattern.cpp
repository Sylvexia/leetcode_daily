// 456. 132 Pattern

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int num_3 = INT_MIN;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < num_3)
                return true;
            else {
                while (!st.empty() and nums[i] > st.top()) {
                    num_3 = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};