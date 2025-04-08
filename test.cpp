#include <stdio.h>

using namespace std;

int main()
{
    char a[10];
    char *names[] = {"jason", "wendy", "henry", "susan"};
    char *name = names[2];
    char **p = names;
    printf("%d, %d, %d, %d, %d\n", sizeof(a), sizeof(names), sizeof(name), sizeof(names[2]), sizeof(name[2]));
    printf("%s, %s", names[2], *(p+4));
}