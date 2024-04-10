// 950. Reveal Cards In Increasing Order

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());

        vector<int> res(deck.size());
        int target = 0;
        for (int d = 0; d < deck.size(); d++) {
            if (d > 0) {
                int count_zero = 0;
                while (count_zero < 2) {
                    target = (target + 1) % deck.size();
                    count_zero += (res[target] == 0);
                }
            }
            res[target] = deck[d];
        }
        return res;
    }
};