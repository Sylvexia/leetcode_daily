// 62. Unique Paths

#include <algorithm>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
            return 1;

        m--;
        n--;

        if (n > m)
            swap(m, n);

        int j = 1;
        long result = 1;

        for (int i = m + n; i > m; i--)
        {
            result *= i;
            result /= j;

            j++;
        }

        return result;
    }
};