// 1189. Maximum Number of Balloons

#include <iostream>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    constexpr bool isMatch(unordered_map<char, int> &u_map)
    {
        if (u_map['b'] < 1 or u_map['a'] < 1 or u_map['l'] < 2 or
            u_map['o'] < 2 or u_map['n'] < 1)
            return false;
        return true;
    }

    constexpr void decrement(unordered_map<char, int> &u_map)
    {
        u_map['b'] -= 1;
        u_map['a'] -= 1;
        u_map['l'] -= 2;
        u_map['o'] -= 2;
        u_map['n'] -= 1;
        return;
    }

public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> u_map;
        for (char c : text)
            u_map[c]++;
        int res = 0;
        while (isMatch(u_map)) {
            res++;
            decrement(u_map);
        }
        return res;
    }
};