#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        auto condition = [&](int mid) -> bool {
            if (citations.size() - mid <= citations[mid])
                return true;
            return false;
        };
        int left = 0, right = citations.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (condition(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return citations.size() - left;
    }
};