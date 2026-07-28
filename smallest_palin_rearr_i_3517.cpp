// 3517. Smallest Palindromic Rearrangement I

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    string smallestPalindrome(string s)
    {
        map<char, int> map;
        for (char c : s)
            map[c]++;
        string front, mid, back;
        for (auto [key, val] : map) {
            for (int i = 0; i < val / 2; i++)
                front.push_back(key);
            if (val % 2 == 0)
                continue;
            mid.push_back(key);
        }
        back = front;
        ranges::reverse(back);
        return front + mid + back;
    }
};