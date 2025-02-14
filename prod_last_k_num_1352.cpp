// 1352. Product of the Last K Numbers

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class ProductOfNumbers
{
    vector<int> prefix;

public:
    ProductOfNumbers() { prefix.push_back(1); }

    void add(int num)
    {
        if (num)
            prefix.push_back(prefix.back() * num);
        else
            prefix = {1};
    }
    int getProduct(int k)
    {
        return k < prefix.size() ? prefix.back() / prefix[prefix.size() - k - 1]
                                 : 0;
    }
};