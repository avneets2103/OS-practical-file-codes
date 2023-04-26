// Writing a Program to Simulate SJF Scheduling Algorithm
#include <stdio.h>
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
void sort_by_burst_time(struct process p[], int n)
{
    int i, j;
    struct process temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].burst_time > p[j + 1].burst_time)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void calculate_completion_time(struct process p[], int n)
{
    int i, completion_time = 0;
    for (i = 0; i < n; i++)
    {
        completion_time += p[i].burst_time;
        p[i].completion_time = completion_time;
    }
}
void calculate_turnaround_time(struct process p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
    }
}
void calculate_waiting_time(struct process p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}
void print_result(struct process p[], int n)
{
    int i;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
printf("\nPID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
for(i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i].pid, p[i].arrival_time,
               p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
        avg_turnaround_time += p[i].turnaround_time;
        avg_waiting_time += p[i].waiting_time;
}
printf("\nAverage Turnaround Time = %f\nAverage Waiting Time = %f\n",
avg_turnaround_time/n, avg_waiting_time/n);
}
int main()
{
int n, i;
struct process p[20];
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter the arrival time and burst time for each process:\n");
for (i = 0; i < n; i++)
{
    printf("Process %d:\n", i + 1);
    printf("Arrival Time: ");
    scanf("%d", &p[i].arrival_time);
    printf("Burst Time: ");
    scanf("%d", &p[i].burst_time);
    p[i].pid = i + 1;
}
sort_by_burst_time(p, n);
calculate_completion_time(p, n);
calculate_turnaround_time(p, n);
calculate_waiting_time(p, n);
print_result(p, n);
return 0;
}
