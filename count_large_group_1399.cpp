// 1399. Count Largest Group

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> uMap;
        for (int i = 1; i <= n; i++) {
            int cur = 0;
            int temp = i;
            while (temp) {
                cur += temp % 10;
                temp /= 10;
            }
            uMap[cur]++;
        }

        int res = 0;
        int maxVal = INT_MIN;
        for (auto [key, val] : uMap) {
            if (val > maxVal) {
                maxVal = val;
                res = 1;
            } else if (val == maxVal)
                res++;
        }
        return res;
    }
};