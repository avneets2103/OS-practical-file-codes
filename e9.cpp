// Writing a Program to Simulate Deadlock Avoidance

#include <stdio.h>
int main()
{
    int i, j, n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int
        allocation[n][n],
        max[n][n], need[n][n], available[n], work[n], finish[n], sequence[n], seq_index = 0;
    // Initialize finish array
    for (i = 0; i < n; i++)
        finish[i] = 0;
    // Input allocation and max matrices
    printf("\nEnter allocation matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &allocation[i][j]);
    printf("\nEnter max matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &max[i][j]);
    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    // Input available resources
    printf("\nEnter available resources: ");
    for (i = 0; i < n; i++)
        scanf("%d", &available[i]);
    // Initialize work array
    for (i = 0; i < n; i++)
        work[i] = available[i];
    // Check for safety
    int flag = 0, count = 0;
    while (count < n)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int temp = 0;
                for (j = 0; j < n; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        temp = 1;
                        break;
                    }
                }
                if (temp == 0)
                {
                    finish[i] = 1;
                    sequence[seq_index++] = i;
                    for (j = 0; j < n; j++)
                        work[j] += allocation[i][j];
                    flag = 1;
                    count++;
                }
            }
        }
        if (flag == 0)
            break;
    }
    if (count == n)
    {
        printf("\nSafe sequence is: ");
        for (i = 0; i < n; i++)
            printf("%d ", sequence[i]);
        printf("\n");
    }
    else
        printf("\nSystem is in unsafe state.\n");
    return 0;
}
