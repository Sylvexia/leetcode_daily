// 415. Add Strings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        string res;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';

            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};