// 2976. Minimum Cost to Convert String I

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long minimumCost(string source,
                          string target,
                          vector<char> &original,
                          vector<char> &changed,
                          vector<int> &cost)
    {
        vector<vector<long long int>> graph(26,
                                            vector<long long int>(26, INT_MAX));

        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++) {
            int orig_idx = original[i] - 'a';
            int chan_idx = changed[i] - 'a';
            graph[orig_idx][chan_idx] =
                min(graph[orig_idx][chan_idx], (long long int) cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        long long int res = 0;
        for (int i = 0; i < source.size(); i++) {
            int src_idx = source[i] - 'a';
            int tgt_idx = target[i] - 'a';

            if (graph[src_idx][tgt_idx] >= INT_MAX)
                return -1;
            res += graph[src_idx][tgt_idx];
        }

        return res;
    }
};