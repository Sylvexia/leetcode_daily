// 2645. Minimum Additions to Make Valid String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int addMinimum(string word)
    {
        vector<bool> visited(word.size(), false);
        int ret = 0;
        int n = word.size();

        for (int i = 0; i < n - 2; i++)
        {
            if (word[i] == 'a' and word[i + 1] == 'b' and word[i + 2] == 'c')
            {
                visited[i] = true;
                visited[i + 1] = true;
                visited[i + 2] = true;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (visited[i])
                continue;

            if (word[i] == 'a')
            {
                if (word[i + 1] == 'b' or word[i + 1] == 'c')
                {
                    visited[i] = true;
                    visited[i + 1] = true;
                    ret++;
                }
            }

            else if (word[i] == 'b')
            {
                if (word[i + 1] == 'c')
                {
                    visited[i] = true;
                    visited[i + 1] = true;
                    ret++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                ret += 2;
        }

        return ret;
    }
};