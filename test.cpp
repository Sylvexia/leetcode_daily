#include <bits/stdc++.h>

using namespace std;

bool catter(int meow)
{
    int asdflkja;
    int arr[69] = {0};
    return true;
}

struct UWU
{
    int a = 10;
    int b = 29;
    int arr[69];
};

int main()
{
    long long int *plong;
    int *pint;
    char *pchar;
    bool *pbool;
    UWU *pstruct;
    bool (*pfunc)(int) = &catter;

    printf("long pointer size:%ld\n", sizeof(plong));
    printf("int pointer size:%ld\n", sizeof(pint));
    printf("char pointer size:%ld\n", sizeof(pchar));
    printf("bool pointer size:%ld\n", sizeof(pbool));
    printf("struct pointer size:%ld\n", sizeof(pstruct));
    printf("function pointer size:%ld\n", sizeof(pfunc));
    printf("struct size:%ld\n", sizeof(UWU));
}