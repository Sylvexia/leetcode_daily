#include <bits/stdc++.h>

// 2696. Minimum String Length After Removing Substrings

using namespace std;

class Solution
{
public:
    int minLength(string s)
    {
        int old_size = 0;
        while (true)
        {
            string temp;

            for (auto ch : s)
            {
                if (temp.size() and temp.back() == 'A')
                {
                    if (ch == 'B')
                    {
                        temp.pop_back();
                        continue;
                    }
                }
                if (temp.size() and temp.back() == 'C')
                {
                    if (ch == 'D')
                    {
                        temp.pop_back();
                        continue;
                    }
                }

                temp.push_back(ch);
            }
            s = temp;
            if (temp.size() == old_size)
                break;

            old_size = temp.size();
        }
        return old_size;
    }
};
