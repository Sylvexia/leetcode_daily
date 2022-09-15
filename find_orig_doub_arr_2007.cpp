// 2007. Find Original Array From Doubled Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        if (changed.size() % 2)
            return {};

        unordered_map<int, int> count{};
        vector<int> keys{};
        vector<int> res{};

        for (int a : changed)
            count[a]++;

        for (auto ele : count)
            keys.push_back(ele.first);

        sort(keys.begin(), keys.end());

        for (int key : keys)
        {
            if (count[key] > count[2 * key])
                return {};

            for (int i = 0; i < count[key]; ++i, count[2 * key]--)
                res.push_back(key);
        }

        return res;
    }
};