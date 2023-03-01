// 912. Sort an Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

class Solution
{
    int m_partition(vector<int> &data, int start, int end)
    {
        if (start >= end)
            return -1;

        int pivot = start, left = pivot + 1, right = end;

        while (left <= right)
        {
            if (data[left] < data[pivot])
                left++;
            else if (data[right] >= data[pivot])
                right--;
            else
                swap(data[left], data[right]);
        }
        swap(data[right], data[pivot]);

        return right;
    }
    void q_sort(vector<int> &data, int start, int end)
    {
        if (start >= end)
            return;

        int pivot = m_partition(data, start, end);

        q_sort(data, start, pivot);
        q_sort(data, pivot + 1, end);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        q_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

class Solution
{
    int m_partition(vector<int> &data, int start, int end)
    {
        if (start >= end)
            return -1;

        int pivot = start, left = pivot + 1, right = end;

        while (left <= right)
        {
            if (data[left] < data[pivot])
                left++;
            else if (data[right] >= data[pivot])
                right--;
            else
                swap(data[left], data[right]);
        }
        swap(data[right], data[pivot]);

        return right;
    }
    void q_sort(vector<int> &data, int start, int end)
    {
        if (start >= end)
            return;

        int pivot = m_partition(data, start, end);

        q_sort(data, start, pivot);
        q_sort(data, pivot + 1, end);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        q_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ret;

        for (auto &ele : nums)
            pq.push(ele);

        while (pq.size())
        {
            ret.push_back(pq.top());
            pq.pop();
        }

        return ret;
    }
};

class Solution
{
    void m_merge(vector<int> &data, int low, int mid, int high)
    {
        if (low >= high)
            return;

        int l = low, r = mid + 1, k = 0, size = high - low + 1;

        vector<int> sorted(size, 0);

        while (l <= mid && r <= high)
            sorted[k++] = data[l] < data[r] ? data[l++] : data[r++];

        while (l <= mid)
            sorted[k++] = data[l++];

        while (r <= high)
            sorted[k++] = data[r++];

        for (k = 0; k < size; k++)
            data[k + low] = sorted[k];
    }

    void merge_sort(vector<int> &data, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (high - low) / 2 + low;

        merge_sort(data, low, mid);
        merge_sort(data, mid + 1, high);
        m_merge(data, low, mid, high);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};