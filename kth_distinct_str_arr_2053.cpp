// 2053. Kth Distinct String in an Array

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> u_map;

        for (string &str : arr)
            u_map[str]++;

        int count = 0;
        for (string &str : arr) {
            count += (u_map[str] == 1);
            if (count == k)
                return str;
        }
        return "";
    }
};