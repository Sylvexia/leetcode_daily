// 1942. The Number of the Smallest Unoccupied Chair

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        vector<int> order(n);
        for (int i = 0; i < n; i++)
            order[i] = i;

        sort(order.begin(), order.end(),
             [&times](int a, int b) { return times[a][0] < times[b][0]; });

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            taken_seats;

        priority_queue<int, vector<int>, greater<int>> empty_seats;
        for (int i = 0; i < n; i++)
            empty_seats.push(i);

        for (int i : order) {
            int arrival = times[i][0];
            int leave = times[i][1];

            while (!taken_seats.empty() and
                   taken_seats.top().first <= arrival) {
                empty_seats.push(taken_seats.top().second);
                taken_seats.pop();
            }

            int seat = empty_seats.top();
            empty_seats.pop();

            if (i == targetFriend)
                return seat;

            taken_seats.push({leave, seat});
        }
        return -1;
    }
};