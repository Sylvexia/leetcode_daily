// 3016. Minimum Number of Pushes to Type Word II

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> char_count;
        for (char ch : word)
            char_count[ch]++;

        vector<int> count_vec;
        for (auto [key, value] : char_count)
            count_vec.push_back(value);

        sort(count_vec.begin(), count_vec.end(), greater<int>());

        int res = 0;
        for (int i = 0; i < count_vec.size(); i++)
            res += count_vec[i] * (i / 8 + 1);

        return res;
    }
};