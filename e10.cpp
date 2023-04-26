// Writing a Program to Simulate Deadlock Detection

#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESS 10
int request[MAX_PROCESS][MAX_PROCESS],
    allocation[MAX_PROCESS][MAX_PROCESS], available[MAX_PROCESS];
int n, m;
void print_matrix(int matrix[][MAX_PROCESS], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int is_safe_state(int *finish)
{
    int work[MAX_PROCESS], i, j;
    for (i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    for (i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            for (j = 0; j < m; j++)
            {
                if (request[i][j] > work[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                finish[i] = 1;
                for (j = 0; j < m; j++)
                {
                    work[j] += allocation[i][j];
                }
                i = -1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int i, j, *finish, *temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    finish = (int *)malloc(n * sizeof(int));
    temp = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
        temp[i] = 0;
    }
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter the request matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }
    printf("Enter the available matrix:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    printf("Allocation matrix:\n");
    print_matrix(allocation, n, m);
    printf("Request matrix:\n");
    print_matrix(request, n, m);
    printf("Available matrix:\n");
    for (i = 0; i < m; i++)
    {
        printf("%d ", available[i]);
    }
    if (is_safe_state(finish))
    {
        printf("\nThe system is in a safe state.\n");
    }
    else
    {
        printf("\nThe system is not in a safe state.\n");
    }
    free(finish);
    free(temp);
    return 0;
}