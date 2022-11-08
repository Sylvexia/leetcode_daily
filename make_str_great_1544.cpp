// 1544. Make The String Great

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string res = "";

        for (char ch : s)
        {
            if (!res.empty() && abs(int(ch) - int(res.back())) == 32)
            {
                res.pop_back();
                continue;
            }
            else
                res.push_back(ch);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.makeGood("LeEet");
}