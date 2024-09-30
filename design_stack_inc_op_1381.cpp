// 1381. Design a Stack With Increment Operation

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class CustomStack
{
    vector<int> vec;
    int capacity;

public:
    CustomStack(int maxSize) : capacity(maxSize) {}

    void push(int x)
    {
        if (vec.size() == capacity)
            return;
        vec.push_back(x);
    }

    int pop()
    {
        if (vec.empty())
            return -1;
        int res = vec.back();
        vec.pop_back();
        return res;
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < min(k, (int) vec.size()); i++)
            vec[i] += val;
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */