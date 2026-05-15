// 1090. Largest Values From Labels

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int largestValsFromLabels(vector<int> &values,
                              vector<int> &labels,
                              int numWanted,
                              int useLimit)
    {
        using pii = pair<int, int>;

        auto comp = [](pii &a, pii &b) { return a.first > b.first; };

        vector<pii> vec;
        int n = values.size();
        for (int i = 0; i < n; i++)
            vec.push_back({values[i], labels[i]});
        sort(vec.begin(), vec.end(), comp);

        int res = 0;
        unordered_map<int, int> u_map;
        for (int i = 0, used = 0; i < n; i++) {
            auto [val, lab] = vec[i];
            if (used == numWanted)
                return res;
            if (u_map[lab] >= useLimit)
                continue;
            
            u_map[lab]++;
            used++;
            res += val;
        }
        return res;
    }
};