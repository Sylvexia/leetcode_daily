// 1009. Complement of Base 10 Integer

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int bitwiseComplement(int num)
    {
        if (num == 0)
            return 1;
        vector<int> set;
        while (num > 0) {
            int mod = num % 2;
            num /= 2;
            set.push_back(mod);
        }
        int res = 0;
        for (int i = 0; i < set.size(); i++) {
            if (set[i] == 0)
                res += pow(2, i);
        }
        return res;
    }
};