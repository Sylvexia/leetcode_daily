// 434. Number of Segments in a String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countSegments(string s)
    {
        int res = 0;
        int onChar = false;
        for(char c:s)
        {
            if(!onChar and c!=' ')
                res++;
            onChar = c != ' ';
        }
        return res;
    }
};