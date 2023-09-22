// 1207. Unique Number of Occurrences

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> cnt;
        for (int num : arr)
            cnt[num]++;

        unordered_set<int> num_oc;
        for (auto [key, val] : cnt) {
            if (num_oc.find(val) != num_oc.end())
                return false;
            num_oc.insert(val);
        }

        return true;
    }
};