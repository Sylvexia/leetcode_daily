// 2125. Number of Laser Beams in a Bank

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<int> v;
        for (string &str : bank) {
            int num = 0;
            for (char ch : str)
                num += (ch == '1');
            if (!num)
                continue;
            v.push_back(num);
        }

        if (!v.size())
            return 0;

        int res = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            res += v[i] * v[i + 1];
        }
        return res;
    }
};