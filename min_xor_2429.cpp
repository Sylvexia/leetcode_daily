// 2429. Minimize XOR

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int bitCount = bitset<32>(num2).count();
        auto bit1 = bitset<32>(num1);
        auto resBit = bitset<32>(0);

        for (int i = 31; i > 0 and bitCount; i--) {
            if (bit1[i]) {
                resBit[i] = 1;
                bitCount--;
            }
        }

        if (bitCount) {
            for (int i = 0; i < 32 and bitCount; i++) {
                if (!resBit[i]) {
                    resBit.set(i);
                    bitCount--;
                }
            }
        }

        return resBit.to_ulong();
    }
};