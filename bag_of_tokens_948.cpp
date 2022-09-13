// 948. Bag of Tokens

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int res{}, points{}, left{}, right = tokens.size() - 1;
        
        sort(tokens.begin(), tokens.end());

        while (left <= right)
        {
            if (power >= tokens[left])
            {
                power -= tokens[left++];
                res = max(res, ++points);
            }
            else if (points > 0)
            {
                power += tokens[right--];
                points--;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};