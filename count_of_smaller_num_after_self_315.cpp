// 315. count of smaller numbers after self
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
    using pair_it = vector<pair<int, int>>::iterator;

public:
    void sort_count(pair_it left, pair_it right, vector<int> &count)
    {
        if (right - left <= 1)
            return;

        pair_it middle = left + (right - left) / 2;
        sort_count(left, middle, count);
        sort_count(middle, right, count);

        for (pair_it i = left, j = middle; i < middle; i++)
        {
            while (j < right && (*i).first > (*j).first)
                j++;

            count[(*i).second] += j - middle;
        }
        inplace_merge(left, middle, right);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> bind;
        vector<int> count(n, 0);

        for (int i = 0; i < n; ++i)
        {
            bind.push_back(pair<int, int>({nums[i], i}));
        }

        sort_count(bind.begin(), bind.end(), count);
        return count;
    }
};