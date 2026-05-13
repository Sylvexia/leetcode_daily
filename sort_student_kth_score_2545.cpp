// 2545. Sort the Students by Their Kth Score

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        auto comp = [k](vector<int> &a, vector<int> &b) { return a[k] > b[k]; };

        sort(score.begin(), score.end(), comp);
        return score;
    }
};