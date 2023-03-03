// 28. Find the Index of the First Occurrence in a String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();

        for (int i = 0; i < m - n + 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;

                if (j == n - 1)
                    return i;
            }
        }

        return -1;
    }
};