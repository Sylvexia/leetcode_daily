// 295. Find Median from Data Stream

#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
    priority_queue<int> maxHeap{};
    priority_queue<int, vector<int>, greater<int>> minHeap{};

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        return (maxHeap.size() > minHeap.size())
                   ? maxHeap.top()
                   : (maxHeap.top() + minHeap.top()) / 2.0;
    }
};