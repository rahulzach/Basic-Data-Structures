#include<stdio.h>

void linear(int[]);
void binary(int[]);
int i, n;

void main()
{
    int a[10], s;
    printf("enter 0 for linear search and 1 for binary search");
    scanf("%d", &s);
    printf("enter the size of array");
    scanf("%d", &n);
    printf("enter the sorted elements");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if(s == 0)
        linear(a);
    else if(s == 1)
        binary(a);
    else
        printf("enter 1 or 0");
}

void linear(int b[])
{
    int p, flag = 0;
    printf("enter the element to be searched");
    scanf("%d", &p);
    for(i = 0; i < n; i++)
    {
        if(b[i] == p)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        printf("the element is found at %d", i + 1);
    else
        printf("element not found");
}

void binary(int c[])
{
    int low, high, mid, key, pos;
    int q = 0;
    printf("enter the element to be searched");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(key == c[mid])
        {
            pos = mid;
            q = 1;
            break;
        }
        else if(key > c[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(q == 1)
        printf("element is found at %d", pos);
    else
        printf("element not found");
}
