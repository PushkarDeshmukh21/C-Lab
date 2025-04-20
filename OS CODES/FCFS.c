#include <stdio.h>

// Structure to represent a process
typedef struct {
    int processId;
    int arrivalTime;
    int burstTime;
} Process;

void calculateWaitingTime(Process processes[], int n, int waitingTime[])
{
    // Waiting time for the first process is always 0
    waitingTime[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        int waiting = waitingTime[i - 1] + processes[i - 1].burstTime;
        if (waiting < processes[i].arrivalTime) {
            waiting = processes[i].arrivalTime;
        }
        waitingTime[i] = waiting;
    }
}

void calculateTurnaroundTime(Process processes[], int n, int waitingTime[], int turnaroundTime[])
{
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
}

void calculateAverageTime(Process processes[], int n)
{
    int waitingTime[n], turnaroundTime[n], totalWaitingTime = 0, totalTurnaroundTime = 0;

    calculateWaitingTime(processes, n, waitingTime);
    calculateTurnaroundTime(processes, n, waitingTime, turnaroundTime);

    printf("Process\t  Arrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i] - processes[i].arrivalTime;
        totalTurnaroundTime += turnaroundTime[i] - processes[i].arrivalTime;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].arrivalTime,
               processes[i].burstTime, waitingTime[i] - processes[i].arrivalTime, turnaroundTime[i] - processes[i].arrivalTime);
    }

    double avgWaitingTime = (double)totalWaitingTime / n;
    double avgTurnaroundTime = (double)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);
}

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    // Accept process details from the user
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].processId = i + 1;
        printf("\n");
    }

   
    calculateAverageTime(processes, n);

    return 0;
}

