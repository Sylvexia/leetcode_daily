// 1282. Group the People Given the Group Size They Belong To

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> buckets;
        for (int i = 0; i < groupSizes.size(); i++)
            buckets[groupSizes[i]].push_back(i);

        vector<vector<int>> res;
        for (auto &[id, vec] : buckets) {
            while (!vec.empty()) {
                vector<int> temp;

                for (int cnt = 0; cnt < id; cnt++) {
                    temp.push_back(vec.back());
                    vec.pop_back();
                }

                res.push_back(temp);
            }
        }

        return res;
    }
};