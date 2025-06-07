// 3170. Lexicographically Minimum String After Removing Stars

#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
    using pci = pair<char, int>;

public:
    string clearStars(string s)
    {
        priority_queue<pci, vector<pci>, greater<pci>> pq;
        unordered_set<int> uSet;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                uSet.insert(-pq.top().second);
                pq.pop();
            } else {
                pq.push({s[i], -i});
            }
        }
        
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (uSet.count(i) or s[i] == '*')
                continue;
            res += s[i];
        }
        return res;
    }
};