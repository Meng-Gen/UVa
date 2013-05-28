#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    getchar();
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        if (case_id > 1)
        {
            putchar('\n');
        }

        int registers[10] = {};
        int ram[1000] = {};
        int ram_pos = 0;
        
        // Read instructions 
        std::string command;
        while (getline(std::cin, command) && command.size())
        {
            ram[ram_pos] = (command[0] - '0') * 100 
                + (command[1] - '0') * 10 
                + (command[2] - '0');
            ram_pos++;
        }

        // Execute instructions
        ram_pos = 0;
        int num_instructions = 0;
        bool is_halt = false;
        while (!is_halt) 
        {
            int opcode = ram[ram_pos] / 100;
            int operand[2];
            operand[0] = (ram[ram_pos] % 100) / 10;
            operand[1] = ram[ram_pos] % 10;
            
            num_instructions++;
            ram_pos++;            
            switch (opcode)
            {
            // halt
            case 1:
                is_halt = true;
                break;
            // 2dn means set register d to n (between 0 and 9)
            case 2:
                registers[operand[0]] = operand[1];
                break;
            // 3dn means add n to register d
            case 3:
                registers[operand[0]] += operand[1];
                registers[operand[0]] %= 1000;
                break;
            // 4dn means multiply register d by n
            case 4:
                registers[operand[0]] *= operand[1];
                registers[operand[0]] %= 1000;
                break;
            // 5ds means set register d to the value of register s
            case 5:
                registers[operand[0]] = registers[operand[1]];
                break;
            // 6ds means add the value of register s to register d
            case 6:
                registers[operand[0]] += registers[operand[1]];
                registers[operand[0]] %= 1000;
                break;
            // 7ds means multiply register d by the value of register s
            case 7:
                registers[operand[0]] *= registers[operand[1]];
                registers[operand[0]] %= 1000;
                break;
            // 8da means set register d to the value in RAM whose address is 
            // in register a
            case 8:
                registers[operand[0]] = ram[registers[operand[1]]];
                break;
            // 9sa means set the value in RAM whose address is in register a 
            // to the value of register s
            case 9:
                ram[registers[operand[1]]] = registers[operand[0]];
                break;
            // 0ds means goto the location in register d unless register s 
            // contains 0
            case 0:
                if (registers[operand[1]]) 
                {
                    ram_pos = registers[operand[0]];
                }
                break;
            // It should not be here.
            default:
                break;
            }
        }
        printf("%d\n", num_instructions);
    }

    return 0;
}
