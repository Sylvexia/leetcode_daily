// 234. Palindrome Linked List

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> stack{};

        while (head != nullptr)
        {
            stack.push_back(head->val);
            head = head->next;
        }

        int start = 0, end = stack.size() - 1;

        while (start < end)
        {
            if (stack[start] != stack[end])
                return false;
            start++;
            end--;
        }

        return true;
    }
};