// 2490. Circular Sentence

#include <bits/stdc++.h>
#include <sstream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        istringstream iss(sentence);
        string buf;
        vector<string> vec;

        while (iss >> buf)
            vec.push_back(buf);

        int n = vec.size();
        for (int i = 0; i < n; i++) {
            char first = vec[i].back();
            char second = vec[(i + 1) % n].front();
            if (first != second)
                return false;
        }

        return true;
    }
};