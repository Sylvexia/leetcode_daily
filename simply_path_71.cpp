// 71. Simplify Path

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        deque<string> dq;
        string res;

        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
                continue;

            string temp;
            while (i < path.size() and path[i] != '/')
            {
                temp += path[i];
                ++i;
            }

            if (temp == ".")
                continue;
            else if (temp == "..")
            {
                if (dq.size())
                    dq.pop_back();
            }
            else
                dq.push_back(temp);
        }

        while (dq.size())
        {
            res += "/" + dq.front();
            dq.pop_front();
        }

        if (res.size() == 0)
            return "/";

        return res;
    }
};