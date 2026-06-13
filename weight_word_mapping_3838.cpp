// 3838. Weighted Word Mapping

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string res;
        for (string &w : words) {
            int weight = 0;
            for (char c : w) {
                int idx = c - 'a';
                weight += weights[idx];
            }
            weight %= 26;
            char ch = 'z' - weight;
            res.push_back(ch);
        }
        return res;
    }
};