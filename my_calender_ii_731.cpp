#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class MyCalendarTwo
{
    map<int, int> bookCount;

public:
    MyCalendarTwo() {}

    bool book(int cur_start, int cur_end)
    {
        bookCount[cur_start]++;
        bookCount[cur_end]--;

        int overlap = 0;

        for (auto &[key, val] : bookCount) {
            overlap += val;
            if (overlap > 2) {
                bookCount[cur_start]--;
                bookCount[cur_end]++;
                if (bookCount[cur_start] == 0)
                    bookCount.erase(cur_start);
                if (bookCount[cur_end] == 0)
                    bookCount.erase(cur_end);

                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */