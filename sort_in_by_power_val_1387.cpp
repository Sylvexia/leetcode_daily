// 1387. Sort Integers by The Power Value

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

int getStep(int n)
{
    int res = 0;
    while (n != 1) {
        if (n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
        res++;
    }
    return res;
}

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        vector<int> vec;
        for (int i = lo; i <= hi; i++)
            vec.push_back(i);

        auto comp = [](int a, int b) {
            int sa = getStep(a);
            int sb = getStep(b);
            if (sa == sb)
                return a < b;
            return sa < sb;
        };

        ranges::sort(vec, comp);

        return vec[k - 1];
    }
};