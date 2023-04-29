// 2657. Find the Prefix Common Array of Two Arrays

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        unordered_set<int> a_set, b_set;
        vector<int> res(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            if (i > 0)
                res[i] = res[i - 1];

            a_set.insert(A[i]);
            b_set.insert(B[i]);
            if (A[i] == B[i])
            {
                res[i]++;
                continue;
            }
            if (a_set.count(B[i]))
                res[i]++;
            if (b_set.count(A[i]))
                res[i]++;
        }
        return res;
    }
};