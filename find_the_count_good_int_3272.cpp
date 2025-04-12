// 3272. Find the Count of Good Integers

#include <bits/stdc++.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        unordered_set<string> u_set;
        int skip = n & 1;
        int base = pow(10, (n - 1) / 2);
        for (int i = base; i < base * 10; i++) {
            string numString = to_string(i);
            numString += string(numString.rbegin() + skip, numString.rend());
            long long palin = stoll(numString);

            if (palin % k == 0) {
                sort(numString.begin(), numString.end());
                u_set.insert(numString);
            }
        }

        vector<long long> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++)
            factorial[i] = factorial[i - 1] * i;

        long long res = 0;
        for (const string &s : u_set) {
            vector<int> arr(10);
            for (char c : s) {
                arr[c - '0']++;
            }

            long long cur = (n - arr[0]) * factorial[n - 1];

            for (int i : arr)
                cur /= factorial[i];
            res += cur;
        }

        return res;
    }
};