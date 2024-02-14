#include <stdio.h>

#define MAX_PROCESS 10

struct Process
{
    int pid;
    int burstTime;
    int remainingTime;
};

void roundRobin(struct Process processes[], int n, int timeQuantum)
{
    int completed = 0;
    int currentTime = 0;

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remainingTime > 0)
            {
                if (processes[i].remainingTime <= timeQuantum)
                {
                    currentTime += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    completed++;
                }
                else
                {
                    currentTime += timeQuantum;
                    processes[i].remainingTime -= timeQuantum;
                }
                printf("Process %d executed at time %d\n", processes[i].pid, currentTime);
            }
        }
    }
}

int main()
{
    int n;
    struct Process processes[MAX_PROCESS];
    int timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    roundRobin(processes, n, timeQuantum);

    return 0;
}
