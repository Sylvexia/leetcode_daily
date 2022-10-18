// 38. Count and Say

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string res = "1";
        // say res = "552223311"
        //
        while (--n)
        {
            string temp = "";

            for (int i = 0; i < res.size(); i++)
            {
                int count = 1;

                while (i + 1 < res.size() && res[i] == res[i + 1])
                {
                    count++;
                    i++;
                }

                temp += to_string(count) + res[i];
            }
            res = temp;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    for (int i = 1; i <= 30; i++)
    {
        printf("{%d, %s}\n", i, sol.countAndSay(i).c_str());
    }
    return 0;
}