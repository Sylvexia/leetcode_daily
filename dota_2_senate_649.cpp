// 649. Dota2 Senate

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        vector<bool> lost(senate.size(), false);
        int r_num = 0, d_num = 0;

        for (char ch : senate)
        {
            if (ch == 'D')
                d_num++;
            else
                r_num++;
        }

        while (r_num and d_num)
        {
            for (int i = 0; i < senate.size(); i++)
            {
                if (lost[i] == true)
                    continue;

                if (senate[i] == 'D')
                {
                    int j = (i + 1) % senate.size();
                    while (senate[j] == 'D' or lost[j])
                        j = (j + 1) % senate.size();
                    lost[j] = true;
                    r_num--;
                }

                else
                {
                    int j = (i + 1) % senate.size();
                    while (senate[j] == 'R' or lost[j])
                        j = (j + 1) % senate.size();
                    lost[j] = true;
                    d_num--;
                }
                if (d_num == 0)
                    return "Radiant";
                if (r_num == 0)
                    return "Dire";
            }
        }

        return (r_num == 0)
                   ? "Dire"
                   : "Radiant";
    }
};

int main()
{
    Solution sol;

    string str{"DDRRR"};

    cout << sol.predictPartyVictory(str);
}