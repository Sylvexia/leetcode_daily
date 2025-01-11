// 824. Goat Latin

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
    string toGoatLatin(string sentence)
    {
        vector<string> resVec;
        istringstream iss(sentence);
        string buf;
        while (iss >> buf)
            resVec.push_back(buf);

        for (int i = 0; i < resVec.size(); i++) {
            char firstChar = resVec[i][0];
            bool isVowel = firstChar == 'a' || firstChar == 'e' ||
                           firstChar == 'i' || firstChar == 'o' ||
                           firstChar == 'u' || firstChar == 'A' ||
                           firstChar == 'E' || firstChar == 'I' ||
                           firstChar == 'O' || firstChar == 'U';
            if (!isVowel)
                resVec[i] = resVec[i].substr(1) + firstChar;
            resVec[i] += "ma" + string(i + 1, 'a');
        }

        string res;
        for (auto &str : resVec)
            res += str + ' ';
        res.pop_back();

        return res;
    }
};