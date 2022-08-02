// 307. Range Sum Query - Mutable

#include <vector>

using namespace std;

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * This approach is too slow
 *
 *
 *
class NumArray
{

private:
    vector<int> m_nums;

public:
    NumArray(vector<int> &nums) : m_nums(nums){};

    void update(int index, int val)
    {
        m_nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        int result = 0;
        for (int i = left; i <= right; i++)
        {
            result += m_nums[i];
        }
        return result;
    }
};
*/
class Bit
{
private:
    vector<int> m_bit;

public:
    Bit(int size = 0) : m_bit(size + 1, 0){};

    int getSum(int idx)
    {
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
        {
            sum += m_bit[idx];
        }
        return sum;
    }

    void addValue(int idx, int val)
    {
        for (; idx < m_bit.size(); idx += idx & (-idx))
            m_bit[idx] += val;
    }
};

class NumArray
{

private:
    vector<int> m_nums;
    Bit m_bit;

public:
    NumArray(vector<int> &nums) : m_nums(nums), m_bit(nums.size())
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            m_bit.addValue(i + 1, nums[i]);
        }
    };

    void update(int index, int val)
    {
        int diff = val - m_nums[index];
        m_bit.addValue(index + 1, diff);

        m_nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        return m_bit.getSum(right + 1) - m_bit.getSum(left);
    }
};