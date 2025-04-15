// 2179. Count Good Triplets in an Array

#include <bits/stdc++.h>

using namespace std;

// I can't at this one

class BIT
{
    vector<int> tree;

public:
    BIT(int size) : tree(size + 1, 0) {}

    void update(int index, int delta)
    {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index)
    {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> pos2(n), getIndex(n);
        for (int i = 0; i < n; i++)
            pos2[nums2[i]] = i;

        for (int i = 0; i < n; i++)
            getIndex[pos2[nums1[i]]] = i;

        BIT bit(n);
        long long res = 0;
        for (int val = 0; val < n; val++) {
            int pos = getIndex[val];
            int left = bit.query(pos);
            bit.update(pos, 1);
            int right = (n - 1 - pos) - (val - left);
            res += (long long) left * right;
        }
        return res;
    }
};