// 895. Maximum Frequency Stack

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class FreqStack
{
    int maxFreq;
    unordered_map<int, vector<int>> freqStack;
    unordered_map<int, int> getFreq;

public:
    FreqStack() { maxFreq = 0; }

    void push(int val)
    {
        int count = getFreq[val];
        count++;
        getFreq[val] = count;
        freqStack[count].push_back(val);
        maxFreq = max(count, maxFreq);
    }

    int pop()
    {
        auto res = freqStack[maxFreq].back();
        freqStack[maxFreq].pop_back();
        getFreq[res]--;
        if (freqStack[maxFreq].empty())
            maxFreq--;
        return res;
    }
};
