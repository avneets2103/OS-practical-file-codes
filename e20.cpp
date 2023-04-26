// Simulation of LOOK Disk Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void look(int arr[], int head, int n)
{
    int seek_time = 0;
    int distance = 0;
    int direction = 1;
    int curr_pos = head;
    int left[n], right[n];
    int l_count = 0, r_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < head)
        {
            left[l_count++] = arr[i];
        }
        else
        {
            right[r_count++] = arr[i];
        }
    }
    sort(left, l_count);
    sort(right, r_count);
    int i = 0;
    while (i < 2)
    {
        if (direction == 1)
        {
            for (int j = 0; j < r_count; j++)
            {
                distance = abs(right[j] - curr_pos);
                seek_time += distance;
                curr_pos = right[j];
            }
            direction = 0;
            i++;
        }
        else
        {
            for (int j = l_count - 1; j >= 0; j--)
            {
                distance = abs(left[j] - curr_pos);
                seek_time += distance;
                curr_pos = left[j];
            }
            direction = 1;
            i++;
        }
    }
    printf("Total Seek Time: %d\n", seek_time);
}
int main()
{
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of head: ");
    scanf("%d", &head);
    look(requests, head, n);
    return 0;
}