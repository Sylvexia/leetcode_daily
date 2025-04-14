// 1534. Count Good Triplets

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    bool validA = abs(arr[i] - arr[j]) <= a;
                    bool validB = abs(arr[j] - arr[k]) <= b;
                    bool validC = abs(arr[i] - arr[k]) <= c;
                    res += validA && validB && validC;
                }
            }
        }
        return res;
    }
};