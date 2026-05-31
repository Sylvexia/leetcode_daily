// 2126. Destroying Asteroids

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        long long cur = mass;
        int n = asteroids.size();

        for (int a : asteroids) {
            if (cur < a)
                return false;
            cur += a;
        }
        return true;
    }
};