// 2516. Take K of Each Character From Left and Right

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int n = s.size();
        array<int, 3> arr;
        for (int i = 0; i < 3; i++) {
            arr[i] = 0;
        }
        for (auto ch : s) {
            arr[ch - 'a']++;
        }
        if (*min_element(arr.begin(), arr.end()) < k)
            return -1;

        int res = n;
        for (int l = n - 1, r = n - 1; r >= 0; r--) {
            arr[s[r] - 'a']--;
            while (arr[s[r] - 'a'] < k) {
                arr[s[l] - 'a']++;
                l--;
            }
            res = min(res, n - l + r - 1);
        }
        return res;
    }
};