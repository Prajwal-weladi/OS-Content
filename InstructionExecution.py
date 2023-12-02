class CPU:
    def __init__(self):
        self.registers = [0] * 8  # 8 general-purpose registers
        self.pc = 0  # Program Counter
        self.memory = [0] * 3000  # Simulated memory

    def load_register(self, reg, value):
        self.registers[reg] = value

    def store_register(self, reg, address):
        if address < len(self.memory):
            self.memory[address] = self.registers[reg]
        else:
            print(f"Error: Memory address {address} out of range.")

    def compare_register(self, reg1, reg2):
        return self.registers[reg1] == self.registers[reg2]

    def branch_if_true(self, condition, offset):
        if condition:
            self.pc += offset
        else:
            self.pc += 1

    def execute_instruction(self, instruction):
        opcode = instruction[0]
        if opcode == "LR":
            reg = instruction[1]
            value = instruction[2]
            self.load_register(reg, value)
        elif opcode == "SR":
            reg = instruction[1]
            address = instruction[2]
            self.store_register(reg, address)
        elif opcode == "CR":
            reg1 = instruction[1]
            reg2 = instruction[2]
            condition = self.compare_register(reg1, reg2)
            return condition
        elif opcode == "BT":
            condition = instruction[1]
            offset = instruction[2]
            self.branch_if_true(condition, offset)
        else:
            print(f"Unknown opcode: {opcode}")

# Example usage:
if __name__ == "__main__":
    cpu = CPU()

    program = [
        ["LR", 1, 42],     # Load Register R1 with value 42
        ["SR", 1, 1000],   # Store the value in R1 to memory address 1000
        ["CR", 1, 2],      # Compare R1 and R2
        ["BT", True, 2],   # Always branch forward 2 instructions
        ["SR", 2, 2000],   # Store the value in R2 to memory address 2000
        # Add more instructions here
    ]

    while cpu.pc < len(program):
        instruction = program[cpu.pc]
        result = cpu.execute_instruction(instruction)
        if result is not None:
            print(f"Comparison result: {result}")
        cpu.pc += 1
