// 443. String Compression

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0, j = 0;

        while (j < chars.size())
        {
            char cur = chars[j];
            int count = 0;

            while (j < chars.size() and chars[j] == cur)
                j++, count++;

            chars[i++] = cur;

            if (count > 1)
            {
                string count_str = to_string(count);
                for (auto c : count_str)
                    chars[i++] = c;
            }
        }

        return i;
    }
};