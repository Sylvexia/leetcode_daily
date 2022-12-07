// 202. Happy Number

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while ((n != 1) && (set.find(n) == set.end()))
        {
            set.insert(n);
            int square_sum = 0;
            while (n)
            {
                int mod = n % 10;
                square_sum += (mod * mod);
                n /= 10;
            }
            n = square_sum;
        }
        return n == 1;
    }
};

int main()
{
    Solution sol;
    sol.isHappy(19);
}