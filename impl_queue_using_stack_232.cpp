// 232. Implement Queue using Stacks

#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
    stack<int> input, output;

    void dump()
    {
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        dump();
        int top = output.top();
        output.pop();
        return top;
    }

    int peek()
    {
        dump();
        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};