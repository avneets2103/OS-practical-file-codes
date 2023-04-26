// Writing a Program to Simulate FCFS Disk Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 1000
int main()
{
    int requests[MAX_REQUESTS], n, i, head_position, total_seek_time;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    if (n > MAX_REQUESTS)
    {
        printf("Maximum number of requests exceeded.\n");
        return 1;
    }
    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head_position);
    total_seek_time = abs(head_position - requests[0]);
    for (i = 1; i < n; i++)
    {
        total_seek_time += abs(requests[i] - requests[i - 1]);
    }
    printf("Total seek time: %d\n", total_seek_time);
    return 0;
}