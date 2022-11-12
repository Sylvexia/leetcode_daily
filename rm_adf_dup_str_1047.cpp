// 1047. Remove All Adjacent Duplicates In String

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res{};
        for(char ch:s)
        {
            if(!res.empty()&&res.back()==ch)
            {
                res.pop_back();
                continue;
            }
            
            res.push_back(ch);
        }
        return res;        
    }
};