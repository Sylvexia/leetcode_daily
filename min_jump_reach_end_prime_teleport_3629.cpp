// 3629. Minimum Jumps to Reach End via Prime Teleportation

#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    static const int MX = 10000001;

    static vector<bool> isPrime;
    static bool sieveBuilt;

    void buildSieve()
    {
        if (sieveBuilt)
            return;
        sieveBuilt = true;

        isPrime.assign(MX, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < MX; ++i) {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j < MX; j += i)
                isPrime[j] = false;
        }
    }

public:
    int minJumps(vector<int> &nums)
    {
        buildSieve();

        int n = nums.size();

        int maxV = *max_element(nums.begin(), nums.end());

        vector<vector<int>> getIndices(maxV + 1);
        for (int i = 0; i < n; i++)
            getIndices[nums[i]].push_back(i);

        queue<int> q;
        q.push(0);

        vector<int> dist(n, -1);
        dist[0] = 0;

        unordered_set<int> usedValue;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int nextDist = dist[cur] + 1;
            int value = nums[cur];

            // normal moves
            if (cur - 1 >= 0 && dist[cur - 1] == -1) {
                dist[cur - 1] = nextDist;
                q.push(cur - 1);
            }

            if (cur + 1 < n && dist[cur + 1] == -1) {
                dist[cur + 1] = nextDist;
                q.push(cur + 1);
            }

            // teleport only if prime
            if (!isPrime[value])
                continue;
            if (usedValue.count(value))
                continue;

            usedValue.insert(value);

            for (int mul = value; mul <= maxV; mul += value) {
                if (getIndices[mul].empty()) continue;

                for (int idx : getIndices[mul]) {
                    if (dist[idx] != -1) continue;

                    dist[idx] = nextDist;
                    q.push(idx);
                }
            }
        }

        return dist[n - 1];
    }
};

// static definitions
vector<bool> Solution::isPrime;
bool Solution::sieveBuilt = false;