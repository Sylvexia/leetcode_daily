// 1491. Average Salary Excluding the Minimum and Maximum Salary

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int min = *min_element(salary.begin(), salary.end());
        int max = *max_element(salary.begin(), salary.end());
        int sum = accumulate(salary.begin(), salary.end(), 0 - min - max);
        return (double)sum / (salary.size() - 2);
    }
};

class Solution
{
public:
    double average(vector<int> &salary)
    {
        double sum = 0;
        int min_ele = INT_MAX, max_ele = INT_MIN;
        for (int i = 0; i < salary.size(); i++)
        {
            sum += salary[i];
            min_ele = min(min_ele, salary[i]);
            max_ele = max(max_ele, salary[i]);
        }
        return (sum - min_ele - max_ele) / (salary.size() - 2);
    }
};