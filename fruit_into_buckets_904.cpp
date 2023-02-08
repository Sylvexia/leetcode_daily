// 904. Fruit Into Baskets

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> count_map{};
        int i{}, j{};

        for (i = 0, j = 0; j < fruits.size(); ++j)
        {
            count_map[fruits[j]]++;

            if (count_map.size() > 2)
            {
                --count_map[fruits[i]];
                if (count_map[fruits[i]] == 0)
                    count_map.erase(fruits[i]);
                    
                i++;
            }
        }

        return j - i;
    }
};