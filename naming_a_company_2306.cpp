// 2306. Naming a Company

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long ret{0};
        unordered_set<string> u_set{};

        for (auto &i : ideas)
            u_set.insert(i);

        for (int i = 0; i < ideas.size(); ++i)
        {
            for (int j = i + 1; j < ideas.size(); ++j)
            {
                swap(ideas[i][0], ideas[j][0]);
                if (u_set.find(ideas[i]) == u_set.end() and
                    u_set.find(ideas[j]) == u_set.end())
                    ret = ret + 2;
                swap(ideas[i][0], ideas[j][0]);
            }
        }

        return ret;
    }
}; // TLE

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long res{0};
        array<unordered_set<string>, 26> group;

        for (auto &i : ideas)
            group[i[0] - 'a'].insert(i.substr(1));

        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                unordered_set<string> u_set;
                u_set.insert(group[i].begin(), group[i].end());
                u_set.insert(group[j].begin(), group[j].end());
                res += ((group[i].size() - u_set.size()) *
                        (group[j].size() - u_set.size()));
            }
        }

        return res * 2;
    }
};