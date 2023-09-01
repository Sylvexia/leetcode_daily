// 77. Combinations

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void backtrack(int start, int end, int size, vector<int> &gen)
    {
        if (gen.size() == size) {
            res.push_back(gen);
            return;
        }

        if (start > end)
            return;

        gen.push_back(start);
        backtrack(start + 1, end, size, gen);
        gen.pop_back();
        backtrack(start + 1, end, size, gen);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> gen;
        backtrack(1, n, k, gen);
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> res;

    void backtrack(int start, int end, int size, vector<int> &gen)
    {
        if (gen.size() == size) {
            res.push_back(gen);
            return;
        }

        for (int i = start; i <= end; i++) {
            gen.push_back(i);
            backtrack(i + 1, end, size, gen);
            gen.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> gen;
        backtrack(1, n, k, gen);
        return res;
    }
};