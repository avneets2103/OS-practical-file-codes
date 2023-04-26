// Write a program to simulate SSTF disk scheduling algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_REQUESTS 100
struct Request
{
    int id;
    int track;
};
int main()
{
    int n_requests;
    struct Request requests[MAX_REQUESTS];
    int i, j, current_track, min_track, min_index, total_seek_time;
    printf("Enter the number of requests: ");
    scanf("%d", &n_requests);
    printf("Enter the requests:\n");
    for (i = 0; i < n_requests; i++)
    {
        printf("Request %d:\n", i + 1);
        printf("Enter the request ID: ");
        scanf("%d", &requests[i].id);
        printf("Enter the requested track number: ");
        scanf("%d", &requests[i].track);
    }
    current_track = 0;
    total_seek_time = 0;
    for (i = 0; i < n_requests; i++)
    {
        min_track = INT_MAX;
        min_index = -1;
        for (j = 0; j < n_requests; j++)
        {
            if (requests[j].track != -1)
            {
                int diff = abs(requests[j].track - current_track);
                if (diff < min_track)
                {
                    min_track = diff;
                    min_index = j;
                }
            }
        }
        if (min_index != -1)
        {
            total_seek_time += min_track;
            current_track = requests[min_index].track;
            requests[min_index].track = -1;
        }
    }
    printf("Total Seek Time: %d\n", total_seek_time);
    return 0;
}