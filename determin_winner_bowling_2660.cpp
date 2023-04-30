// 2660. Determine the Winner of a Bowling Game

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int s1 = 0, s2 = 0;
        unordered_set<int> p1_i, p2_i;
        for (int i = 0; i < player1.size(); i++)
        {
            s1 += player1[i];
            s2 += player2[i];
            if (player1[i] == 10)
            {
                p1_i.insert(i + 1);
                p1_i.insert(i + 2);
            }
            if (player2[i] == 10)
            {
                p2_i.insert(i + 1);
                p2_i.insert(i + 2);
            }
        }

        for (int i : p1_i)
        {
            if (i < player1.size())
                s1 += player1[i];
        }
        for (int i : p2_i)
        {
            if (i < player2.size())
                s2 += player2[i];
        }
        if (s1 == s2)
            return 0;
        if (s1 > s2)
            return 1;
        return 2;
    }
};