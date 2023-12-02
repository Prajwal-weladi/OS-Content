class Process:
    def __init__(self, pid, arrival_time, burst_time, priority):
        self.pid = pid
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.start_time = 0
        self.completion_time = 0
        self.turnaround_time = 0
        self.waiting_time = 0
        self.response_time = 0

def bubble_sort(processes):
    n = len(processes)
    for i in range(n):
        for j in range(0, n-i-1):
            if processes[i].completion_time < processes[j].completion_time:
                processes[j], processes[j+1] = processes[j+1], processes[j]
    return processes

def gantt_chart(processes):
    print("\nGantt Chart:")
    current_time = 0
    start_time = 0
    time = 0
    CT_sort_processes = bubble_sort(processes)
    for process in CT_sort_processes:
        while current_time < process.completion_time:
            if current_time == process.arrival_time:
                start_time += current_time
            current_time += 1
        time += process.completion_time
        print(f"{start_time} ({process.pid}) {current_time}", end=" || ")
        start_time = current_time
    print()

def main():
    n = int(input("Enter the number of processes: "))
    processes = []

    total_turnaround_time = 0
    total_waiting_time = 0
    total_response_time = 0
    total_idle_time = 0

    is_completed = [0] * 100

    print("Enter process details:")
    for i in range(n):
        pid = i + 1
        arrival_time = int(input(f"Arrival time of process {pid}: "))
        burst_time = int(input(f"Burst time of process {pid}: "))
        priority = int(input(f"Priority of process {pid}: "))
        processes.append(Process(pid, arrival_time, burst_time, priority))

    current_time = 0
    completed = 0
    prev = 0

    while completed != n:
        idx = -1
        mx = -1
        for i in range(n):
            if (
                processes[i].arrival_time <= current_time
                and is_completed[i] == 0
            ):
                if processes[i].priority > mx:
                    mx = processes[i].priority
                    idx = i
                if processes[i].priority == mx:
                    if processes[i].arrival_time < processes[idx].arrival_time:
                        mx = processes[i].priority
                        idx = i
        if idx != -1:
            processes[idx].start_time = current_time
            processes[idx].completion_time = (
                processes[idx].start_time + processes[idx].burst_time
            )
            processes[idx].turnaround_time = (
                processes[idx].completion_time - processes[idx].arrival_time
            )
            processes[idx].waiting_time = (
                processes[idx].turnaround_time - processes[idx].burst_time
            )
            processes[idx].response_time = (
                processes[idx].start_time - processes[idx].arrival_time
            )

            total_turnaround_time += processes[idx].turnaround_time
            total_waiting_time += processes[idx].waiting_time
            total_response_time += processes[idx].response_time
            total_idle_time += processes[idx].start_time - prev

            is_completed[idx] = 1
            completed += 1
            current_time = processes[idx].completion_time
            prev = current_time
        else:
            current_time += 1

    min_arrival_time = 10000000
    max_completion_time = -1
    for i in range(n):
        min_arrival_time = min(min_arrival_time, processes[i].arrival_time)
        max_completion_time = max(
            max_completion_time, processes[i].completion_time
        )

    avg_turnaround_time = total_turnaround_time / n
    avg_waiting_time = total_waiting_time / n
    avg_response_time = total_response_time / n
    throughput = n / (max_completion_time - min_arrival_time)
    schedule_length = max_completion_time - min_arrival_time

    print("\nPID\t\tAT\t\tBT\t\tPriority\t\tCT\t\tTAT\t\tWT\t\tRT")
    for i in range(n):
        print(f"{processes[i].pid}\t\t{processes[i].arrival_time}\t\t"
            f"{processes[i].burst_time}\t\t\t{processes[i].priority}\t\t\t"
            f"{processes[i].completion_time}\t\t"
            f"{processes[i].turnaround_time}\t\t{processes[i].waiting_time}\t\t"
            f"{processes[i].response_time}")
    print(f"\nAverage Turnaround Time = {avg_turnaround_time:.2f}")
    print(f"Average Waiting Time = {avg_waiting_time:.2f}")
    print(f"Average Response Time = {avg_response_time:.2f}")
    print("Schedule Length:", schedule_length)
    print(f"Throughput = {throughput:.2f} process/unit time")
    gantt_chart(processes)

if __name__ == "__main__":
    print("PRIORITY BASED NON-PREEMPTIVE SCHEDULING ALGORITHM\n")
    main()
