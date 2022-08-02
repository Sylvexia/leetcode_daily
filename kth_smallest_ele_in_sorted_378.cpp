// 378. Kth Smallest Element in a Sorted Matrix

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int> pq;

        for(auto row : matrix)
        {
            for(auto col : row)
            {
                pq.push(col);
                if(pq.size()>k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};