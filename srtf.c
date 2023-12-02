#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_arrival_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void sort_by_remaining_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].remaining_time > processes[j + 1].remaining_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void print_gantt_chart(int gantt_chart[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", gantt_chart[i]);
    }
    printf("|\n\n");
}

void srtf(Process processes[], int n) {
    int total_time = 0;
    int *gantt_chart = (int *)malloc(sizeof(int) * 100);
    int gantt_index = 0;

    sort_by_arrival_time(processes, n);

    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < n) {
        int shortest_process_index = -1;
        int shortest_remaining_time = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_remaining_time && processes[i].remaining_time > 0) {
                shortest_remaining_time = processes[i].remaining_time;
                shortest_process_index = i;
            }
        }

        if (shortest_process_index == -1) {
            current_time++;
            continue;
        }

        processes[shortest_process_index].remaining_time--;
        gantt_chart[gantt_index++] = processes[shortest_process_index].process_id;

        current_time++;

        if (processes[shortest_process_index].remaining_time == 0) {
            completed_processes++;
        }
    }

    print_gantt_chart(gantt_chart, gantt_index);

    free(gantt_chart);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(sizeof(Process) * n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    srtf(processes, n);

    free(processes);

    return 0;
}
