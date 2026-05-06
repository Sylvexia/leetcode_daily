// 3248. Snake in Matrix

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {
        int cur = 0;
        unordered_map<string, int> u_map{
            {"RIGHT", 1}, {"LEFT", -1}, {"UP", -n}, {"DOWN", n}};
        for (string &str : commands)
            cur += u_map[str];
        return cur;
    }
};