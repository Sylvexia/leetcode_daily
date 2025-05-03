// 1007. Minimum Domino Rotations For Equal Row

#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        vector<int> topMap(7), botMap(7), sameMap(7);
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            topMap[tops[i]]++;
            botMap[bottoms[i]]++;
            if (tops[i] == bottoms[i])
                sameMap[tops[i]]++;
        }
        for (int i = 1; i <= 6; i++) {
            if (topMap[i] + botMap[i] - sameMap[i] == n)
                return n - max(topMap[i], botMap[i]);
        }
        return -1;
    }
};