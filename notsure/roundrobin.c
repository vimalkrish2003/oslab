//Process scheduling using round robin algorithm in operating system
#include <stdio.h>


struct process
{
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
};

void print_processes(struct process *processes, int n) 
{
    printf("pid\t burst_time\tarrival_time \twaiting_time \t turnaround_time\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time,processes[i].waiting_time,processes[i].turnaround_time);
    }
}


void round_robin_scheduling(struct process *processes, int n, int quantum)
{
    int time = 0;
    int completed = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed < n)
    {
        if (processes[i].remaining_time <= quantum && processes[i].remaining_time > 0)
        {
            time += processes[i].remaining_time;
            processes[i].remaining_time = 0;
            flag = 1;
        }
        else if (processes[i].remaining_time > 0)
        {
            processes[i].remaining_time -= quantum;
            time += quantum;
        }

        if (processes[i].remaining_time == 0 && flag == 1)
        {
            completed++;
            processes[i].completion_time = time;
            processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
            total_waiting_time += processes[i].waiting_time;
            total_turnaround_time += processes[i].turnaround_time;
            flag = 0;
        }

        if (i == n - 1)
        {
            i = 0;
        }
        else if (processes[i + 1].arrival_time <= time)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    printf("\n\n");
    printf("Round Robin Scheduling: \n");
    printf("Processes: \n");
    print_processes(processes, n);
    printf("Average waiting time: %f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time / n);
}





int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time, and arrival time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].pid = i + 1;
        processes[i].completion_time=0;
        processes[i].waiting_time=0;
        processes[i].turnaround_time=0;
        processes[i].remaining_time=processes[i].burst_time;

        
    }

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("Processes: \n");
    print_processes(processes, n);

    round_robin_scheduling(processes, n, quantum);

    return 0;
}



