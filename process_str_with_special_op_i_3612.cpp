// 3612. Process String with Special Operations I

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    string processStr(string s) {
        string res;
        for(char c:s)
        {
            if(c == '*')
            {
                if(res.size())
                    res.pop_back();
            }
            else if(c == '#')
                res.append(res);
            else if(c=='%')
                reverse(res.begin(), res.end());
            else
                res.push_back(c);
        }
        return res;
    }
};