// 1054. Distant Barcodes

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        unordered_map<int, int> u_map;
        for (int b : barcodes)
            u_map[b]++;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, less<pii>> pq;

        for (auto [key, value] : u_map)
            pq.push({value, key});

        vector<int> res;
        while (pq.size() >= 2) {
            auto [first_count, first_key] = pq.top();
            pq.pop();
            res.push_back(first_key);
            auto [second_count, second_key] = pq.top();
            pq.pop();
            res.push_back(second_key);

            first_count--;
            second_count--;

            if (first_count)
                pq.push({first_count, first_key});
            if (second_count)
                pq.push({second_count, second_key});
        }

        if (!pq.empty()) {
            res.push_back(pq.top().second);
        }

        return res;
    }
};