// 76. Minimum Window Substring

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool check_val(unordered_map<char, queue<int>> letter_map,
                   unordered_map<char, int> req)
    {
        for (auto [key, val] : req) {
            if (val != letter_map[key].size())
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        unordered_map<char, queue<int>> letter_map;
        unordered_map<char, int> req;
        int min_size = INT_MAX;
        int global_max = INT_MIN, global_min = INT_MAX;

        for (int i = 0; i < t.size(); i++)
            req[t[i]]++;

        for (int i = 0; i < s.size(); i++) {
            char letter = s[i];
            if (req.find(letter) == req.end())
                continue;

            letter_map[letter].push(i);
            if (letter_map[letter].size() > req[letter]) {
                letter_map[letter].pop();
            }

            if (!check_val(letter_map, req))
                continue;

            int local_max = INT_MIN, local_min = INT_MAX;
            for (auto &[key, val] : letter_map) {
                local_max = max(local_max, val.front());
                local_max = max(local_max, val.back());
                local_min = min(local_min, val.front());
                local_min = min(local_min, val.back());
            }

            int local_size = local_max - local_min + 1;
            if (local_size < min_size) {
                global_max = local_max;
                global_min = local_min;
                min_size = local_size;
            }
        }

        return (min_size == INT_MAX) ? "" : s.substr(global_min, min_size);
    }
};

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> req;
        for (char ch : t)
            req[ch]++;

        int l = 0, r = 0;
        int counter = t.size();

        int head = 0;
        int min_size = INT_MAX;

        while (r < s.size()) {
            if (req[s[r]] > 0)
                counter--;
            req[s[r]]--;
            r++;

            while (counter == 0) {
                if (r - l < min_size) {
                    head = l;
                    min_size = r - l;
                }
                req[s[l]]++;

                counter += req[s[l]] > 0;
                l++;
            }
        }

        return (min_size == INT_MAX) ? "" : s.substr(head, min_size);
    }
};