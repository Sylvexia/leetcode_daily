// 1233. Remove Sub-Folders from the Filesystem

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> res{folder[0]};
        for (int i = 1; i < folder.size(); i++) {
            string back = res.back();
            back += "/";
            if (folder[i].compare(0, back.size(), back) != 0)
                res.push_back(folder[i]);
        }
        return res;
    }
};