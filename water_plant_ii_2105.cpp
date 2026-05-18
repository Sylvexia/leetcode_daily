// 2105. Watering Plants II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int refill = 0;

    void water(vector<int>& plants,
               int& capacity,
               int full,
               int idx)
    {
        if (capacity < plants[idx]) {
            capacity = full;
            refill++;
        }

        capacity -= plants[idx];
    }

public:
    int minimumRefill(vector<int>& plants,
                      int capacityA,
                      int capacityB)
    {
        int l = 0;
        int r = plants.size() - 1;

        int fullA = capacityA;
        int fullB = capacityB;

        while (l < r) {
            water(plants, capacityA, fullA, l++);
            water(plants, capacityB, fullB, r--);
        }

        if (l == r) {
            int remain = max(capacityA, capacityB);

            if (remain < plants[l])
                refill++;
        }

        return refill;
    }
};