// 3274. Check if Two Chessboard Squares Have the Same Color

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        int a = coordinate1[0] - 'a' + 1;
        int b = coordinate1[1] - '0';
        int c = coordinate2[0] - 'a' + 1;
        int d = coordinate2[1] - '0';

        return (a + b) % 2 == (c + d) % 2;
    }
};