// 2336. Smallest Number in Infinite Set

#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet
{
    set<int> added;
    int cur = 1;

public:
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        if (added.size())
        {
            int smallest = *(added.begin());
            added.erase(added.begin());
            return smallest;
        }
        return cur++;
    }

    void addBack(int num)
    {
        if (num < cur)
            added.insert(num);
    }
};