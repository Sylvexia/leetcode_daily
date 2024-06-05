// 1002. Find Common Characters

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        unordered_map<char, int> u_map;
        for (char ch : words[0])
            u_map[ch]++;

        for (auto &word : words) {
            unordered_map<char, int> local_map;
            for (auto ch : word)
                local_map[ch]++;
            for (auto [key, value] : u_map)
                u_map[key] = min(u_map[key], local_map[key]);
        }

        vector<string> res;
        for (auto [key, value] : u_map) {
            for (int i = 0; i < value; i++)
                res.push_back({key});
        }
        return res;
    }
};