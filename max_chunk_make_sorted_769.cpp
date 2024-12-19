// 769. Max Chunks To Make Sorted

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int seq_sum = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            seq_sum += i;
            seq_sum -= arr[i];
            res += (seq_sum == 0);
        }
        return res;
    }
};