// 901. Online Stock Span

#include <bits/stdc++.h>

using namespace std;

class StockSpanner
{
    vector<int> data;
    stack<int> idx;

public:
    StockSpanner() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }

    int next(int price)
    {
        while (!idx.empty() and price >= data[idx.top()])
            idx.pop();
        int top = (idx.empty()) ? -1 : idx.top();
        idx.push(data.size());
        data.push_back(price);
        return data.size() - top - 1;
    }
};