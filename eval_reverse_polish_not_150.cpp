// 150. Evaluate Reverse Polish Notation

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_set<string> arith{"+", "-", "*", "/"};
        stack<int> todo;

        for (auto ele : tokens)
        {
            if (arith.find(ele) == arith.end())
            {
                todo.push(stoi(ele));
            }
            else
            {
                int second = todo.top();
                todo.pop();
                int first = todo.top();
                todo.pop();

                if (ele == "+")
                    todo.push(first + second);
                else if (ele == "-")
                    todo.push(first - second);
                else if (ele == "*")
                    todo.push(first * second);
                else if (ele == "/")
                    todo.push(first / second);
            }
        }

        return todo.top();
    }
};