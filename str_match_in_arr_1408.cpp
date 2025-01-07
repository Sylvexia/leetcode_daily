// 1408. String Matching in an Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        unordered_set<string> u_set;
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                string strA = words[i];
                string strB = words[j];
                if (strA.size() > strB.size())
                    swap(strA, strB);
                for (int k = 0; k < strB.size() - strA.size() + 1; k++) {
                    if (strB.substr(k, strA.size()) == strA)
                        u_set.insert(strA);
                }
            }
        }
        for (auto &ele : u_set)
            res.push_back(ele);
        return res;
    }
};