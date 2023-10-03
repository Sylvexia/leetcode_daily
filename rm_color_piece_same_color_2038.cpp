// 2038. Remove Colored Pieces if Both Neighbors are the Same Color

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int alice = 0, bob = 0;
        for (int i = 2; i < colors.size(); i++) {
            if (colors[i] == 'A' and colors[i - 1] == 'A' and
                colors[i - 2] == 'A')
                alice++;
            if (colors[i] == 'B' and colors[i - 1] == 'B' and
                colors[i - 2] == 'B')
                bob++;
        }

        return alice > bob;
    }
};