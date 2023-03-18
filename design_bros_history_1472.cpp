// 1472. Design Browser History

#include <bits/stdc++.h>

using namespace std;

class BrowserHistory
{
    vector<string> history;
    int pos;

public:
    BrowserHistory(string homepage)
        : pos(0)
    {
        history.push_back(homepage);
    }

    void visit(string url)
    {
        pos++;
        history.resize(pos);
        history.push_back(url);
    }

    string back(int steps)
    {
        pos = max(0, pos - steps);
        return history[pos];
    }

    string forward(int steps)
    {
        pos = min((int)history.size() - 1, pos + steps);
        return history[pos];
    }
};