// 1791. Find Center of Star Graph

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

// class Solution
// {
// public:
//     int findCenter(vector<vector<int>> &edges)
//     {
//         unordered_map<int, int> u_map;

//         u_map[edges[0][0]]++;
//         u_map[edges[0][1]]++;
//         u_map[edges[1][0]]++;
//         u_map[edges[1][1]]++;

//         for (auto [key, count] : u_map)
//             if (count == 2)
//                 return key;
//         return -1;
//     }
// };

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]
                   ? edges[0][0]
                   : edges[0][1];
    }
};