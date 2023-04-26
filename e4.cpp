// Writing a Program to Simulate FCFS CPU Scheduling Algorithm
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} process;
void read_processes(process *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i + 1;
    }
}
void sort_processes(process *p, int n)
{
    int i, j;
    process temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].arrival_time > p[j].arrival_time)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
void fcfs(process *p, int n)
{
    int i;
    float total_turnaround_time = 0, total_waiting_time = 0;
    p[0].completion_time = p[0].burst_time + p[0].arrival_time;
    p[0].turnaround_time = p[0].completion_time - p[0].arrival_time;
    p[0].waiting_time = p[0].turnaround_time - p[0].burst_time;
    for (i = 1; i < n; i++)
    {
        p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
    for (i = 0; i < n; i++)
    {
        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;
    }
printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time,
               p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
}
printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time/n);
printf("Average Waiting Time: %.2f\n", total_waiting_time/n);
}
int main()
{
int n;
process *p;
printf("Enter the number of processes: ");
scanf("%d", &n);
p = (process *)malloc(n * sizeof(process));
read_processes(p, n);
sort_processes(p, n);
fcfs(p, n);
return 0;
}