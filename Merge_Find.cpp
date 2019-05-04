#include<stdio.h>

void init(int a[] , int s[])
{
    int i;
    for ( i = 0; i < 100 ; i++)
    {
        a[i] = i;
        s[i] = -1;
    }
}

int Find(int x, int a[])
{
    int r = x;
    while(a[r] != r)
    {
        r = a[r];
    }

    int i = x;
    while(i != a[i])
    {
        x = a[i];
        a[i] = r;
        i = x;
    }
    return r;
}

void Merge(int x ,int y ,int a[])
{
    int rx = Find(x ,a), ry = Find(y, a);
    if(rx == ry) return;
    else
    {
        a[x] = y;
    }
}

int main()
{
    int a[100] , s[100];
    int i;
    init(a,s);
    Merge(3, 5, a);
    Merge(2, 5, a);
    Merge(4, 11, a);
    Merge(6, 11, a);
    i = Find(2 ,a);
    printf("%d", i);
    Merge(3, 6, a);
    i = Find(6 ,a);
    printf("%d", i);
    return 0;
}