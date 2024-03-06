// 1268. Search Suggestions System

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord)
    {
        sort(products.begin(), products.end());

        vector<vector<string>> res;
        int n = products.size();
        int l = 0, r = n - 1;

        for (int i = 0; i < searchWord.size(); i++) {
            char ch = searchWord[i];
            while (l < n and (i >= products[l].size() or ch != products[l][i]))
                l++;
            while (r >= 0 and (i >= products[r].size() or ch != products[r][i]))
                r--;

            if (l > r) {
                res.push_back({});
                continue;
            }

            vector<string> gen;
            for (int j = l; j < min(l + 3, r + 1); j++)
                gen.push_back(products[j]);
            res.push_back(gen);
        }

        return res;
    }
};