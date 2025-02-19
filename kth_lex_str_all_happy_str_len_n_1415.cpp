// 1415. The k-th Lexicographical String of All Happy Strings of Length n

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<char> set{'a', 'b', 'c'};

    void dfs(string &gen, int n, int &k, string &res)
    {
        if (k < 0)
            return;

        if (gen.size() == n) {
            k--;
            if (k == 0) {
                res = string(gen);
                return;
            }
            return;
        }

        for (char ch : set) {
            if (gen.empty() || gen.back() != ch) {
                gen.push_back(ch);
                dfs(gen, n, k, res);
                gen.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k)
    {
        string gen, res;
        dfs(gen, n, k, res);
        return res;
    }
};