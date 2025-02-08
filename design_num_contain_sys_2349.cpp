// 2349. Design a Number Container System

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class NumberContainers
{
    unordered_map<int, set<int>> getIndex;
    unordered_map<int, int> getVal;

public:
    NumberContainers() {}

    void change(int index, int number)
    {
        if (getVal.count(index)) {
            int orig = getVal[index];
            getIndex[orig].erase(index);
            if (getIndex[orig].empty())
                getIndex.erase(orig);
        }
        getVal[index] = number;
        getIndex[number].insert(index);
    }

    int find(int number)
    {
        if (getIndex.count(number))
            return *getIndex[number].begin();
        return -1;
    }
};