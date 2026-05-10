// 3541. Find Most Frequent Vowel and Consonant

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
    int maxFreqSum(string s)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int v_max = 0;
        int c_max = 0;
        for (auto [key, val] : freq) {
            if (vowels.count(key))
                v_max = max(v_max, val);
            else
                c_max = max(c_max, val);
        }
        return v_max + c_max;
    }
};