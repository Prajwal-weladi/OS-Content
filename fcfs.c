#include <stdio.h>

void fcfs(int processes[], int n, int burst_times[], int arrival_times[]) {
    int completion_times[n], waiting_times[n], turnaround_times[n];

    // Calculate completion time, turnaround time, and waiting time for each process
    completion_times[0] = arrival_times[0] + burst_times[0];
    turnaround_times[0] = completion_times[0] - arrival_times[0];
    waiting_times[0] = 0;

    for (int i = 1; i < n; i++) {
        completion_times[i] = completion_times[i-1] + burst_times[i];
        turnaround_times[i] = completion_times[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];
    }

    // Display results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrival_times[i], burst_times[i], completion_times[i], turnaround_times[i], waiting_times[i]);
    }

    // Calculate average waiting time and average turnaround time
    float average_waiting_time = 0, average_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        average_waiting_time += waiting_times[i];
        average_turnaround_time += turnaround_times[i];
    }

    average_waiting_time /= n;
    average_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_times[n];
    int arrival_times[n];

    // Input process names, burst times, and arrival times
    printf("Enter process names, burst times, and arrival times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_times[i]);
        printf("Arrival Time: ");
        scanf("%d", &arrival_times[i]);
    }

    // Perform FCFS scheduling
    fcfs(processes, n, burst_times, arrival_times);

    return 0;
}
