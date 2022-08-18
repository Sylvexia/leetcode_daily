// 1338. Reduce Array Size to The Half

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        const int MAX = 100000;
        int ans = 0, maxFreq = 0;
        array<int, MAX + 1> freq{0}, freqBucket{0};

        for (auto num : arr)
            maxFreq = max(maxFreq, ++freq[num]);

        for (int i = 0; i <= MAX; i++)
            freqBucket[freq[i]]++;

        for (int i = maxFreq, required_size = arr.size() / 2; required_size > 0; i--)
        {
            if (!freqBucket[i])
                continue;

            int freq_num = min(freqBucket[i], required_size / i + (required_size % i > 0));

            required_size -= freq_num * i;

            ans += freq_num;
        }
        return ans;
    }
};