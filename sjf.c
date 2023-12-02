#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sjf(int processes[], int n, int burst_times[], int arrival_times[]) {
    // Sort processes based on arrival time and burst time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_times[j] > arrival_times[j + 1] || 
                (arrival_times[j] == arrival_times[j + 1] && burst_times[j] > burst_times[j + 1])) {
                swap(&arrival_times[j], &arrival_times[j + 1]);
                swap(&burst_times[j], &burst_times[j + 1]);
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    int completion_times[n], waiting_times[n], turnaround_times[n], response_times[n];

    // Calculate completion time, response time, waiting time, and turnaround time for each process
    int current_time = 0; // Keep track of current time

    // Display Gantt chart header
    printf("\nGantt Chart:\n");

    for (int i = 0; i < n; i++) {
        // Response time is the time at which the process first gets the CPU
        response_times[i] = current_time - arrival_times[i];
        if (response_times[i] < 0) {
            response_times[i] = 0; // If the process arrives later than the current time, set response time to 0
            current_time = arrival_times[i];
        }

        // Calculate completion time, turnaround time, and waiting time
        completion_times[i] = current_time + burst_times[i];
        turnaround_times[i] = completion_times[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];

        // Display Gantt chart
        printf("%d (%d) %d", processes[i], current_time, burst_times[i]);
        if (i < n - 1) {
            printf(" || ");
        }
        current_time += burst_times[i];
    }
    printf("\n");

    // Display results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tResponse Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrival_times[i], burst_times[i], completion_times[i], response_times[i], waiting_times[i], turnaround_times[i]);
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

    // Perform SJF scheduling
    sjf(processes, n, burst_times, arrival_times);

    return 0;
}
