// 946. Validate Stack Sequences

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0, j = 0;

        for (int val : pushed)
        {
            pushed[i] = val;
            while (i >= 0 and pushed[i] == popped[j])
                i--, j++;
            i++;
        }
        return i == 0;
    }
};