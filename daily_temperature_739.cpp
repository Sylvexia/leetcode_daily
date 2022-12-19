// 739. Daily Temperatures

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++)
        {
            for (int j = i + 1; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    res[i] = j - i;
                    break;
                }
            }
        }

        return res;
    }
}; // nope

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size());
        vector<int> stack;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (stack.size() &&
                   temperatures[i] > temperatures[stack.back()])
            {
                res[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }

        return res;
    }
};
