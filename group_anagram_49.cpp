// 49. Group Anagrams

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hash_string;
        for (auto &str : strs)
        {
            string temp = str;
            sort(str.begin(), str.end());
            hash_string[str].push_back(temp);
        }
        vector<vector<string>> res;
        for (auto &ele : hash_string)
            res.push_back(ele.second);

        return res;
    }
};