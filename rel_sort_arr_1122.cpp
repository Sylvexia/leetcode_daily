// 1122. Relative Sort Array

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> u_map_1;
        for (auto ele : arr1)
            u_map_1[ele]++;

        unordered_set<int> u_set_2(arr2.begin(), arr2.end());

        vector<int> res;
        for (auto ele : arr2) {
            for (int i = 0; i < u_map_1[ele]; i++)
                res.push_back(ele);
            u_map_1.erase(ele);
        }

        vector<int> remain;
        for (auto [key, count] : u_map_1) {
            for (int i = 0; i < count; i++)
                remain.push_back(key);
        }

        sort(remain.begin(), remain.end());
        res.insert(res.end(), remain.begin(), remain.end());

        return res;
    }
};