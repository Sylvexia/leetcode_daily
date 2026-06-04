// 3751. Total Waviness of Numbers in Range I

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int totalWaviness(int num1, int num2)
    {
        int res = 0;
        for (int num = num1; num <= num2; num++) {
            string str_num = to_string(num);
            int len = str_num.size();
            for (int i = 1; i < len - 1; i++) {
                res +=
                    (str_num[i] > str_num[i + 1]) && (str_num[i] > str_num[i - 1]);
                res +=
                    (str_num[i] < str_num[i + 1]) && (str_num[i] < str_num[i - 1]);
            }
        }
        return res;
    }
};