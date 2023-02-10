// Alien Dictionary

// lintcode: 892

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        map<char, int> degree{};
        map<char, vector<char>> graph{};

        for (auto &word : words)
        {
            for (auto &ch : word)
                degree[ch] = 0;
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            int l = min(words[i].size(), words[i + 1].size());
            bool isPrefix{true};
            int j{};
            for (j = 0; j < l; j++)
            {
                char a{words[i][j]};
                char b{words[i + 1][j]};

                if (a != b)
                {
                    graph[a].push_back(b);
                    degree[b]++;
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix and j < words[i].size() and j >= words[i + 1].size())
                return "";
        }

        string res{};
        priority_queue<char, vector<char>, greater<char>> q;

        for (auto [key, value] : degree)
        {
            if (value == 0)
                q.push(key);
        }

        while (!q.empty())
        {
            char a = q.top();
            q.pop();
            res.push_back(a);

            for (char child_ch : graph[a])
            {
                degree[child_ch]--;
                if (degree[child_ch] == 0)
                    q.push(child_ch);
            }
        }

        return res.size() == degree.size() ? res : "";
    }
};