// 2671. Frequency Tracker

#include <bits/stdc++.h>

using namespace std;

class FrequencyTracker
{
    unordered_map<int, int> u_map, freq;

public:
    FrequencyTracker()
    {
    }

    void add(int number)
    {
        if (u_map.count(number) and u_map[number] > 0)
        {
            freq[u_map[number]]--;
            u_map[number]++;
            freq[u_map[number]]++;
        }
        else
        {
            u_map[number]++;
            freq[u_map[number]]++;
        }
    }

    void deleteOne(int number)
    {
        if (u_map.count(number) and u_map[number] > 0)
        {
            freq[u_map[number]]--;
            u_map[number]--;

            if (freq[u_map[number]] == 0)
                freq.erase(u_map[number]);

            freq[u_map[number]]++;
        }
    }

    bool hasFrequency(int frequency)
    {
        return freq.count(frequency) and freq[frequency] != 0;
    }
};