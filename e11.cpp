// Writing a Program to Simulate Best-Fit Contiguous Memory Allocation

#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int memory[MAX_SIZE], allocation[MAX_SIZE];
    int n, m;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &memory[i]);
    }
    printf("\nEnter the number of processes: ");
    scanf("%d", &m);
    printf("Enter the size of each process:\n");
    for (int i = 0; i < m; i++)
    {
        int process_size;
        scanf("%d", &process_size);
        // Find the best-fit memory block
        int best_fit_index = -1;
        for (int j = 0; j < n; j++)
        {
            if (memory[j] >= process_size)
            {
                if (best_fit_index == -1 || memory[j] < memory[best_fit_index])
                {
                    best_fit_index = j;
                }
            }
        }
        // Allocate memory to the process
        if (best_fit_index != -1)
        {
            allocation[i] = best_fit_index;
            memory[best_fit_index] -= process_size;
        }
        else
        {
            allocation[i] = -1;
        }
    }
    printf("\nProcess\tProcess Size\tBlock Index\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d\t%d\t\t", i + 1, allocation[i] + 1);
        if (allocation[i] != -1)
        {
            printf("%d\n", allocation[i] + 1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }
    return 0;
}
