// 1476. Subrectangle Queries

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class SubrectangleQueries
{
    vector<vector<int>> m_rect;

public:
    SubrectangleQueries(vector<vector<int>> &rectangle) : m_rect(rectangle) {}

    void updateSubrectangle(int row1,
                            int col1,
                            int row2,
                            int col2,
                            int newValue)
    {
        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++)
                m_rect[i][j] = newValue;
        }
    }

    int getValue(int row, int col) { return m_rect[row][col]; }
};