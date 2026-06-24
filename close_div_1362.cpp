// 1362. Closest Divisors

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<int> findDiv(int n)
    {
        int start = sqrt(n);
        for (int i = start; i >= 1; i--) {
            if (n % i == 0)
                return {i, n / i};
        }
        return {-1, -1};
    }

public:
    vector<int> closestDivisors(int num)
    {
        vector<int> a = findDiv(num + 1);
        vector<int> b = findDiv(num + 2);
        if(a[1] - a[0] < b[1] - b[0])
            return a;
        return b;
    }
};