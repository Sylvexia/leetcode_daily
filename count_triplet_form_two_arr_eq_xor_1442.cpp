// 1442. Count Triplets That Can Form Two Arrays of Equal XOR

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        arr.insert(arr.begin(), 0);
        int n = arr.size(), res = 0;
        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j])
                    res += j - i - 1;
            }
        }
        return res;
    }
};