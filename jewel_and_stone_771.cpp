// 771. Jewels and Stones

#include <bits/stdc++.h>
#include <string>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> u_set{jewels.begin(), jewels.end()};
        int res = 0;
        for(char c:stones)
            res+=u_set.count(c);
        return res;
    }
};