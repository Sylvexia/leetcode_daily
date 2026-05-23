// 809. Expressive Words

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int expressiveWords(string s, vector<string> &words)
    {
        int res = 0;
        for (auto w : words) {
            int s_idx = 0;
            int w_idx = 0;
            bool cur_res = true;
            while (s_idx < s.size() and w_idx < w.size()) {
                if (s[s_idx] != w[w_idx]) {
                    cur_res = false;
                    break;
                }
                int s_count = 1;
                while (s_idx + 1 < s.size() and s[s_idx] == s[s_idx + 1]) {
                    s_count++;
                    s_idx++;
                }
                int w_count = 1;
                while (w_idx + 1 < w.size() and w[w_idx] == w[w_idx + 1]) {
                    w_count++;
                    w_idx++;
                }
                if (s_count < w_count) {
                    cur_res = false;
                    break;
                }
                if (s_count > w_count and s_count < 3) {
                    cur_res = false;
                    break;
                }
                s_idx++;
                w_idx++;
            }
            if (s_idx != s.size() or w_idx != w.size())
                cur_res = false;
            res += cur_res;
        }
        return res;
    }
};