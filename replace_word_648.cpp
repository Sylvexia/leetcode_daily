// 648. Replace Words

#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> u_set(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        vector<string> res_vec;
        string buf;
        while (getline(ss, buf, ' '))
            res_vec.push_back(buf);

        for (auto &s : res_vec) {
            for (int i = 1; i < s.size(); i++) {
                string temp = s.substr(0, i);
                if (u_set.count(temp)) {
                    s = temp;
                    break;
                }
            }
        }

        string res;

        for (auto &s : res_vec) {
            res.append(s);
            res += ' ';
        }

        return {res.begin(), res.end() - 1};
    }
};