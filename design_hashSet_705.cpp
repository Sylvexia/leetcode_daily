// 705. Design HashSet

#include <bits/stdc++.h>

using namespace std;

class MyHashSet
{
    array<bool, 1000001> arr;

public:
    MyHashSet()
    {
        for (int i = 0; i < arr.size(); i++)
            arr[i] = false;
    }

    void add(int key) { arr[key] = true; }

    void remove(int key) { arr[key] = false; }

    bool contains(int key) { return arr[key]; }
};