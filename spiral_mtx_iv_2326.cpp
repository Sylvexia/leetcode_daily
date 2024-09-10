// 2326. Spiral Matrix IV

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int i = 0;
        int j = 0;
        for (ListNode *trav = head; trav; trav = trav->next) {
            res[i][j] = trav->val;
            int temp_i = i + dirs[d].first;
            int temp_j = j + dirs[d].second;
            if (temp_i < 0 or temp_j < 0 or temp_i >= m or temp_j>=n or
                res[temp_i][temp_j] != -1)
                d = (d + 1) % 4;
            i += dirs[d].first;
            j += dirs[d].second;
        }
        return res;
    }
};