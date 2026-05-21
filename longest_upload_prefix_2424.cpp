// 2424. Longest Uploaded Prefix

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class LUPrefix
{
    unordered_set<int> u_set;
    int max_len;

public:
    LUPrefix(int n) : max_len{0} {}

    void upload(int video)
    {
        u_set.insert(video);
        while (u_set.count(max_len + 1))
            max_len++;
    }

    int longest() { return max_len; }
};
