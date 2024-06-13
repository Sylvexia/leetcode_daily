// 2037. Minimum Number of Moves to Seat Everyone

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int res = 0;
        for (int i = 0; i < seats.size(); i++)
            res += (abs(seats[i] - students[i]));

        return res;
    }
};