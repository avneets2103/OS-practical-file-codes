// Writing a Program to Simulate Multilevel Feedback Queue Scheduling Algorithm

#include <stdio.h>
#define MAX_PROCESS 50
// process structure
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int queue_num;
    int turnaround_time;
    int waiting_time;
};
// queues for each level
struct process queue0[MAX_PROCESS], queue1[MAX_PROCESS],
    queue2[MAX_PROCESS];
int front0 = -1, rear0 = -1, front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;
// time quantum for each level
int time_quantum[] = {10, 20, 40};
// function to add a process to a queue
void enqueue(struct process p, int queue_num)
{
    switch (queue_num)
    {
    case 0:
        if (rear0 == MAX_PROCESS - 1)
        {
            printf("Queue 0 is full.\n");
            return;
        }
        if (front0 == -1)
        {
            front0 = 0;
        }
        rear0++;
        queue0[rear0] = p;
        break;
    case 1:
        if (rear1 == MAX_PROCESS - 1)
        {
            printf("Queue 1 is full.\n");
            return;
        }
        if (front1 == -1)
        {
            front1 = 0;
        }
        rear1++;
        queue1[rear1] = p;
        break;
    case 2:
        if (rear2 == MAX_PROCESS - 1)
        {
            printf("Queue 2 is full.\n");
            return;
        }
        if (front2 == -1)
        {
            front2 = 0;
        }
        rear2++;
        queue2[rear2] = p;
        break;
    default:
        printf("Invalid queue number.\n");
        break;
    }
}
// function to remove a process from a queue
struct process dequeue(int queue_num)
{
    struct process p = {-1, -1, -1, -1, -1, -1, -1, -1};
    switch (queue_num)
    {
    case 0:
        if (front0 == -1 || front0 > rear0)
        {
            printf("Queue 0 is empty.\n");
            return p;
        }
        p = queue0[front0];
        front0++;
        break;
    case 1:
        if (front1 == -1 || front1 > rear1)
        {
            printf("Queue 1 is empty.\n");
            return p;
        }
        p = queue1[front1];
        front1++;
        break;
    case 2:
        if (front2 == -1 || front2 > rear2)
        {
            printf("Queue 2 is empty.\n");
            return p;
        }
        p = queue2[front2];
        front2++;
        break;
    default:
        printf("Invalid queue number.\n");
        break;
    }
    return p;
}
// function to check if a queue is empty
int is_empty(int queue_num)
{
    switch (queue_num)
    {
    case 0:
        return (front0 == -1 || front0 > rear0);
    case 1:
        return (front1 == -1 || front1 > rear1);
    case 2:
        return (front2 == -1 || front2 > rear2);
    default:
        printf("Invalid queue number.\n");
        return -1;
    }
}
