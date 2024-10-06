// 1813. Sentence Similarity III

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
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> vec1, vec2;
        stringstream ss1(sentence1), ss2(sentence2);
        string buff;
        while (ss1 >> buff)
            vec1.push_back(buff);
        while (ss2 >> buff)
            vec2.push_back(buff);

        int size_1 = vec1.size();  // should be smaller
        int size_2 = vec2.size();

        if (size_1 > size_2) {
            swap(size_1, size_2);
            swap(vec1, vec2);
        }

        int l = 0;
        int r1 = size_1 - 1;
        int r2 = size_2 - 1;

        while (l < size_1 and vec1[l] == vec2[l])
            l++;

        while (r1 >= 0 and vec1[r1] == vec2[r2]) {
            r1--;
            r2--;
        }

        return r1 < l;
    }
};