// 729. My Calendar I

#include <map>
#include <utility>

using namespace std;

class MyCalendar
{
private:
    map<int, int> bookings;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto next = bookings.upper_bound(start);
        
        if (next != bookings.end() && (*next).second < end)
            return false;

        bookings.insert({end, start});

        return true;
    }
};
