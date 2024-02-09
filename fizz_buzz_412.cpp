// 412. Fizz Buzz

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            string temp;
            if (i % 3 == 0)
                temp.append("Fizz");
            if (i % 5 == 0)
                temp.append("Buzz");

            if (temp.empty())
                temp.append(to_string(i));

            res.push_back(temp);
        }
        return res;
    }
};