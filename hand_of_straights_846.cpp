// 846. Hand of Straights

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        unordered_map<int, int> u_map;

        for (auto e : hand)
            u_map[e]++;

        while (!u_map.empty())
        {
            auto [min_key, val] = *min_element(u_map.begin(), u_map.end());

            int key = min_key;
            int key_end = key + groupSize;
            while (key < key_end)
            {
                if (u_map.find(key) == u_map.end())
                    return false;
                u_map[key]--;
                if (u_map[key] == 0)
                    u_map.erase(key);

                key++;
            }
        }

        return true;
    }
};

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> o_map;

        for (auto e : hand)
            o_map[e]++;

        for (auto it : o_map)
        {
            if (o_map[it.first] > 0)
            {
                for (int i = groupSize - 1; i >= 0; i--)
                {
                    if ((o_map[it.first + i] -= o_map[it.first]) < 0)
                        return false;
                }
            }
        }

        return true;
    }
};