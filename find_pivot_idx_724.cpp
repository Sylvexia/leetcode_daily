// 724. Find Pivot Index

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left{}, right{};   
        
        for(int num:nums)
        {
            right+=num;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            right-=nums[i];
            if(left==right)
                return i;
            left+=nums[i];
        }
        
        return -1;
    }
};