// 1539. Kth Missing Positive Number

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        for (auto e : arr)
        {
            if (e <= k)
                k++;
        }

        return k;
    }
};

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0, r = arr.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (arr[m] - m - 1 < k)
                l = m + 1;
            else
                r = m;
        }
        return r + k;
    }
};