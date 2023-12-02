data_buffer = []
memory = [[''] * 4 for _ in range(100)]

# Flags to control data storage
store_data = False

with open('input.txt', 'r') as file:
    for line in file:
        card_type = line[:4]

        if card_type == "$AMJ":
            print("Start of Job: $AMJ")
            store_data = True
        elif card_type == "$DTA":
            print("Data Section: $DTA")
            store_data = False
        elif card_type == "$END":
            print("End of Job: $END")
            break
        elif store_data:
            content = line.strip()
            data_buffer.extend(list(content))

# Determine the number of rows needed in memory
num_rows = (len(data_buffer) + 3) // 4

# Populate the memory with data from the buffer
for i in range(num_rows):
    for j in range(4):
        if data_buffer:
            memory[i][j] = data_buffer.pop(0)

# Print memory contents with a line break every 7 rows
print("\nMemory Contents:")
for i in range(num_rows):
    if i % 7 == 0 and i != 0:
        print()
    print("Row", i + 1, ':', ''.join(memory[i]))
