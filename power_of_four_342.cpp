// 342. Power of Four

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(const int &n)
    {
        return (n > 0) &&
               (n & (n - 1)) == 0 &&
               (n & 0xAAAAAAAA) == 0;
    }
};