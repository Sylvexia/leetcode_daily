// 706. Design HashMap

#include <bits/stdc++.h>

using namespace std;

class MyHashMap
{
    int arr[1000001];

public:
    MyHashMap() { memset(arr, -1, sizeof(arr)); }

    void put(int key, int value) { arr[key] = value; }

    int get(int key) { return arr[key]; }

    void remove(int key) { arr[key] = -1; }
};