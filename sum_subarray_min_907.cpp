// 907. Sum of Subarray Minimums

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<pair<int, int>> stk_p, stk_n;

        vector<long long int> left(arr.size()), right(arr.size());

        for (int i = 0; i < arr.size(); i++)
            left[i] = i + 1;
        for (int i = 0; i < arr.size(); i++)
            right[i] = arr.size() - i;

        for (int i = 0; i < arr.size(); i++) {
            while (!stk_p.empty() and stk_p.top().first > arr[i])
                stk_p.pop();
            left[i] = stk_p.empty() ? i + 1 : i - stk_p.top().second;
            stk_p.push({arr[i], i});

            while (!stk_n.empty() and stk_n.top().first > arr[i]) {
                auto x = stk_n.top();
                stk_n.pop();
                right[x.second] = i - x.second;
            }
            stk_n.push({arr[i], i});
        }

        long long int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            res = (res + arr[i] * left[i] * right[i]) % mod;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> data{3, 1, 2, 4};
    sol.sumSubarrayMins(data);
}