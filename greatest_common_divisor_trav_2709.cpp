// 2709. Greatest Common Divisor Traversal

#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
    vector<int> parent;
    vector<int> size;

public:
    int count;
    UnionFind(int n) : parent(n), size(n, 1), count{n}
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int get_parent(int i)
    {
        if (parent[i] != i)
            parent[i] = get_parent(parent[i]);
        return parent[i];
    }
    void merge(int i, int j)
    {
        int parent_i = get_parent(i), parent_j = get_parent(j);
        if (parent_i == parent_j)
            return;
        if (size[parent_i] < size[parent_j])
            swap(parent_i, parent_j);
        size[parent_i] += size[parent_j];
        parent[parent_j] = parent_i;
        count--;
    }
};

class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size(), m = *max_element(nums.begin(), nums.end());
        UnionFind uf(n);
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int f = 2;
            while (f * f <= nums[i]) {
                if (nums[i] % f == 0) {
                    if (index.count(f))
                        uf.merge(i, index[f]);
                    else
                        index[f] = i;
                    while (nums[i] % f == 0)
                        nums[i] = nums[i] / f;
                }
                f++;
            }
            if (nums[i] > 1) {
                if (index.count(nums[i]))
                    uf.merge(i, index[nums[i]]);
                else
                    index[nums[i]] = i;
            }
        }
        return uf.count == 1;
    }
};