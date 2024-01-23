// 1239. Maximum Length of a Concatenated String with Unique Characters

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<string> m_arr;
    vector<int> m_dp;

    bool is_unique(string &str)
    {
        unordered_set<char> u_set;
        for (auto ch : str) {
            if (u_set.find(ch) != u_set.end())
                return false;
            u_set.insert(ch);
        }
        return true;
    }

    void dfs(int start, string str, int &res)
    {
        if (!is_unique(str))
            return;
        res = max(res, static_cast<int>(str.size()));

        for (int i = start; i < m_arr.size(); i++)
            dfs(i + 1, str + m_arr[i], res);
    }

public:
    int maxLength(vector<string> &arr)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        m_dp.resize(arr.size() + 1, -1);
        m_arr = move(arr);

        string str;
        int res = 0;
        dfs(0, str, res);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> arr = {"cha", "r", "act", "ers"};
    cout << sol.maxLength(arr);
}