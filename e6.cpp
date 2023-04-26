// Writing a Program to Simulate preemptive Priority CPU scheduling algorithm
#include <stdio.h>
#include <stdlib.h>
struct process
{
    int pid;
    int burst_time;
    int priority;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
int main()
{
    int num_processes, i, j, current_time = 0, total_burst_time = 0;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct process p[num_processes], temp;
    for (i = 0; i < num_processes; i++)
    {
        p[i].pid = i + 1;
        printf("Enter the burst time and priority for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].burst_time, &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
        total_burst_time += p[i].burst_time;
    }
    for (i = 0; i < total_burst_time; i++)
    {
        int min_priority = 999, min_priority_index = -1;
        for (j = 0; j < num_processes; j++)
        {
            if (p[j].remaining_time > 0 && p[j].priority < min_priority)
            {
                min_priority = p[j].priority;
                min_priority_index = j;
            }
        }
        p[min_priority_index].remaining_time--;
        if (p[min_priority_index].remaining_time == 0)
        {
            p[min_priority_index].completion_time = i + 1;
            p[min_priority_index].turnaround_time =
                p[min_priority_index].completion_time;
            p[min_priority_index].waiting_time = p[min_priority_index].turnaround_time - p[min_priority_index].burst_time;
            avg_turnaround_time += p[min_priority_index].turnaround_time;
            avg_waiting_time += p[min_priority_index].waiting_time;
        }
    }
printf("\nProcess ID\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
for(i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time,
               p[i].priority, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
}
avg_turnaround_time /= num_processes;
avg_waiting_time /= num_processes;
printf("\nAverage Turnaround Time: %f\nAverage Waiting Time: %f\n",
avg_turnaround_time, avg_waiting_time);
return 0;
}