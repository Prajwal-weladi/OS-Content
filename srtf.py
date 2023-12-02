num_processes = int(input('Enter the number of processes: '))
burst_times = [0] * num_processes
arrival_times = [0] * num_processes
actual_burst_times = [0] * num_processes

for i in range(num_processes):
    actual_burst_times[i] = int(input(f'Enter the burst time for process {i + 1}: '))
    arrival_times[i] = int(input(f'Enter the arrival time for process {i + 1}: '))
    burst_times[i] = [actual_burst_times[i], arrival_times[i], i]

total_burst_time = sum(actual_burst_times)
result_list = []

for i in range(total_burst_time):
    eligible_processes = [process for process in burst_times if process[1] <= i and process[0] > 0]
    if len(eligible_processes) > 0:
        eligible_processes.sort(key=lambda x: x[0])
        burst_times[burst_times.index(eligible_processes[0])][0] -= 1
        if burst_times[burst_times.index(eligible_processes[0])][0] == 0:
            popped_process = burst_times.pop(burst_times.index(eligible_processes[0]))
            result_list.append([popped_process, i + 1])

completion_times = [0] * num_processes
turnaround_times = [0] * num_processes
waiting_times = [0] * num_processes

for i in result_list:
    completion_times[i[0][2]] = i[1]

for i in range(num_processes):
    turnaround_times[i] = completion_times[i] - arrival_times[i]
    waiting_times[i] = turnaround_times[i] - actual_burst_times[i]

print('PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT')
for i in range(num_processes):
    print(f"{i+1}\t\t{arrival_times[i]}\t\t{actual_burst_times[i]}\t\t{completion_times[i]}\t\t{turnaround_times[i]}\t\t{waiting_times[i]}")
print('\nAverage Waiting Time = ', sum(waiting_times) / num_processes)
print('Average Turnaround Time = ', sum(turnaround_times) / num_processes)
