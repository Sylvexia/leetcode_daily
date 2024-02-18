// 2402. Meeting Rooms III

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> res(n, 0);
        priority_queue<int, vector<int>, greater<int>> avail;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;

        for (int i = 0; i < n; i++)
            avail.push(i);

        sort(meetings.begin(), meetings.end());

        for (auto m : meetings) {
            int start = m[0], end = m[1];
            while (!busy.empty() and busy.top().first <= start) {
                avail.push(busy.top().second);
                busy.pop();
            }
            if (!avail.empty() > 0) {
                int top = avail.top();
                res[top]++;
                avail.pop();
                busy.push({end, top});
            } else {
                auto [busy_end, index] = busy.top();
                res[index]++;
                busy.pop();
                busy.push({busy_end + end - start, index});
            }
        }
        return max_element(res.begin(), res.end()) - res.begin();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> data{{0, 10}, {1, 2}, {12, 14}, {13, 15}};
    sol.mostBooked(2, data);
}