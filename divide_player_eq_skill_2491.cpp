// 2491. Divide Players Into Teams of Equal Skill

#include <bits/stdc++.h>
#include <numeric>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        long long sum = accumulate(skill.begin(), skill.end(), (long long) 0);
        int part = sum / (n / 2);
        if (sum % (n / 2) != 0)
            return -1;

        unordered_map<int, int> u_map;
        for (int n : skill)
            u_map[n]++;

        long long res = 0;
        for (auto [key, val] : u_map) {
            if (u_map[key] != u_map[part - key])
                return -1;
            res += ((long long) key * (part - key)) * val;
        }

        return res / 2;
    }
};