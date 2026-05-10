// 2011. Final Value of Variable After Performing Operations

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
    int finalValueAfterOperations(vector<string> &operations)
    {
        unordered_map<string, int> data{
            {"--X", -1}, {"X--", -1}, {"++X", 1}, {"X++", 1}};

        int x = 0;
        for (auto &str : operations) {
            x += data[str];
        }
        return x;
    }
};