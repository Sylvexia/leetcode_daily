//  165. Compare Version Numbers

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int compareVersion(string ver_1, string ver_2)
    {
        int i = 0, j = 0;
        for (; i < ver_1.size() and j < ver_2.size(); i++, j++) {
            int num_1 = 0, num_2 = 0;
            while (i < ver_1.size() and ver_1[i] != '.') {
                num_1 = num_1 * 10 + (ver_1[i] - '0');
                i++;
            }

            while (j < ver_2.size() and ver_2[j] != '.') {
                num_2 = num_2 * 10 + (ver_2[j] - '0');
                j++;
            }

            if (num_1 > num_2)
                return 1;
            if (num_1 < num_2)
                return -1;
        }

        if (i < ver_1.size()) {
            cout << "pos";
            for (; i < ver_1.size(); i++) {
                if (ver_1[i] != '0' and ver_1[i] != '.')
                    return 1;
            }
        }

        if (j < ver_2.size()) {
            for (; j < ver_2.size(); j++) {
                if (ver_2[j] != '0' and ver_2[j] != '.') {
                    return -1;
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    string ver_1 =
        "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    string ver_2 =
        "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0."
        "0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
    sol.compareVersion(ver_1, ver_2);
}