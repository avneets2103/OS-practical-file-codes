// Write a program to simulate C-SCAN disk scheduling algorithm
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int queue[20], visited[20], head, n, i, j, seek_time = 0, diff, max, temp, queue1[20],
                                               queue2[20], temp1 = 0, temp2 = 0;
    float avg_seek_time;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    printf("Enter the queue elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
        visited[i] = 0;
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    // Splitting the queue into two sub-queues
    for (i = 0; i < n; i++)
    {
        if (queue[i] < head)
        {
            queue1[temp1] = queue[i];
            temp1++;
        }
        if (queue[i] > head)
        {
            queue2[temp2] = queue[i];
            temp2++;
        }
    }
    // Sorting the sub-queues in ascending order
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] < queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    // Adding the head to the queue1
    queue1[temp1] = head;
    // Adding the maximum value of the queue2 to the queue1
    queue1[temp1 + 1] = 199;
    // Adding the minimum value of the queue2 to the queue1
    queue1[temp1 + 2] = 0;
    // Setting the current head position to the end of the queue1
    temp1 = temp2 = head;
    // Traversing the queue1 in the forward direction
    for (i = 0; i <= temp1; i++)
    {
        for (j = 0; j < temp1; j++)
        {
            if (queue1[i] == queue[j])
            {
                diff = abs(temp1 - queue[j]);
                seek_time += diff;
                temp1 = queue[j];
                visited[j] = 1;
            }
        }
    }
    // Traversing the queue2 in the forward direction
    for (i = 0; i < temp2; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (queue2[i] == queue[j] && visited[j] == 0)
            {
                diff = abs(temp2 - queue[j]);
                seek_time += diff;
                temp2 = queue[j];
                visited[j] = 1;
            }
        }
    }
    avg_seek_time = seek_time / (float)n;
    printf("Total seek time: %d\n", seek_time);
    printf("Average seek time: %0.2f\n", avg_seek_time);
    return 0;