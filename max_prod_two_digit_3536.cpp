// 3536. Maximum Product of Two Digits

#include <iostream>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxProduct(int n)
    {
        priority_queue<int, vector<int>, less<int>> pq;
        while (n) {
            pq.push(n % 10);
            n /= 10;
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        return a * b;
    }
};