// 48. Rotate Image

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dimension=matrix.size();
        vector<vector<int>> result={};
        result.reserve(dimension*dimension);
        
        for(int i=0;i<dimension;i++)
        {
            vector<int> row;
            for(int j=0;j<dimension;j++)
            {
                row.push_back(matrix[dimension-1-j][i]);
            }
            result.push_back(row);
        }
        
        matrix=result;
    }
};