// 394. Decode String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> chars;
        stack<int> nums;
        string res;

        int num = 0;

        for (char c : s) {
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (isalpha(c))
                res.push_back(c);
            else if (c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            } else if (c == ']') {
                string temp = res;
                for (int i = 0; i < nums.top() - 1; i++)
                    res += temp;

                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string data{"2[abc]3[cd]ef"};
    cout << sol.decodeString(data);
}