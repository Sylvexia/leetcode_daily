// 592. Fraction Addition and Subtraction

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string fractionAddition(string expression)
    {
        constexpr int MAX_MOD = 2520;
        vector<int> numerator;
        vector<int> denominator;

        bool is_positive = true;
        int num = 0;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] >= '0' and expression[i] <= '9')
                num = num * 10 + expression[i] - '0';
            else if (expression[i] == '-') {
                if (i != 0)
                    denominator.push_back(num);
                is_positive = false;
                num = 0;
            } else if (expression[i] == '+') {
                if (i != 0)
                    denominator.push_back(num);
                is_positive = true;
                num = 0;
            } else if (expression[i] == '/') {
                numerator.push_back(is_positive ? num : -num);
                is_positive = true;
                num = 0;
            }
        }
        denominator.push_back(num);
        int num_res = 0;
        for (int i = 0; i < numerator.size(); i++) {
            num_res += numerator[i] * (MAX_MOD / denominator[i]);
        }
        if (num_res == 0)
            return "0/1";
        int gcd_res = gcd(MAX_MOD, num_res);

        num_res /= gcd_res;
        int den_res = MAX_MOD / gcd_res;
        return to_string(num_res) + "/" + to_string(den_res);
    }
};