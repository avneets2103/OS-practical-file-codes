// Writing a Program to Simulate Round Robin Scheduling Algorithm Objective:
#include <stdio.h>
#define MAX_PROCESSES 100
#define TIME_QUANTUM 2
typedef struct
{
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} process;
int main()
{
    int n, i, time, remaining_processes, time_elapsed = 0;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    process p[MAX_PROCESSES];
    remaining_processes = n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time and arrival time of process %d: ", i + 1);
        scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }
printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
for (time = 0; remaining_processes != 0; ) {
        for (i = 0; i < n; i++)
        {
            if (p[i].remaining_time <= TIME_QUANTUM && p[i].remaining_time > 0)
            {
                time += p[i].remaining_time;
                p[i].remaining_time = 0;
                p[i].completion_time = time;
                p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                avg_turnaround_time += p[i].turnaround_time;
                avg_waiting_time += p[i].waiting_time;
                remaining_processes--;
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time,
                       p[i].arrival_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
            }
            else if (p[i].remaining_time > 0)
            {
                p[i].remaining_time -= TIME_QUANTUM;
                time += TIME_QUANTUM;
            }
        }
}
avg_turnaround_time /= n;
avg_waiting_time /= n;
printf("\nAverage Turnaround Time: %f", avg_turnaround_time);
printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
return 0;
}
