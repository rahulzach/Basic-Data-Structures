#include<stdio.h>

void main()
{
    int a[10][10], b[10][3], m, n, s = 1, i = 0, j = 0;
    printf("Sparse matrix\n");
    printf("Enter number of rows");
    scanf("%d", &m);
    printf("Enter number of columns\n");
    scanf("%d", &n);
    for(i = 0; i < m; i++)
    {
        printf("Enter elements of row %d\n", i + 1);
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Entered matrix\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    b[0][0] = m;
    b[0][1] = n;
    s = 1;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
            {
                b[s][0] = i;
                b[s][1] = j;
                b[s][2] = a[i][j];
                s++;
            }
        }
    }
    b[0][2] = s - 1;
    printf("Sparse matrix representation\n");
    for(i = 0; i < s; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
