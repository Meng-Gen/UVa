#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

struct Range
{
    int lower_bound;
    int upper_bound;
};

struct ArrayData
{
    std::string name;
    int base_address;
    int element_size;
    int dim;
    Range dim_range[12];
};

// -----------------------------------------------------------------------------

int N, R;
std::string array_name;
std::map<std::string, ArrayData> symbol_table;

void ReadArrays()
{
    for (int i = 1; i <= N; i++)
    {
        ArrayData array_data;
        std::cin >> array_name >> array_data.base_address >> 
            array_data.element_size >> array_data.dim;

        for (int j = 1; j <= array_data.dim; j++)
        {
            std::cin >> array_data.dim_range[j].lower_bound >> 
                array_data.dim_range[j].upper_bound;
        }
        symbol_table[array_name] = array_data;
    }
}

void QueryPhysicalAddress()
{
    // Input
    std::cin >> array_name;
    ArrayData array_data = symbol_table[array_name];
    int dim = array_data.dim;

    int index_list[11];
    for (int j = 1; j <= dim; j++)
    {
        std::cin >> index_list[j];
    }

    // Calculate physical address = B + C_1(i_1 - L_1) + ... + C_D(i_D - L_D)
    int c[11] = {};
    c[dim] = array_data.element_size;
    for (int j = dim; j >= 2; j--)
    {
        c[j-1] = c[j] * (array_data.dim_range[j].upper_bound -
            array_data.dim_range[j].lower_bound + 1);
    }

    int physical_address = array_data.base_address;
    for (int j = 1; j <= dim; j++)
    {
        physical_address += c[j] * 
            (index_list[j] - array_data.dim_range[j].lower_bound);
    }
    
    // Output
    printf("%s[", array_name.c_str());
    for (int j = 1; j <= dim; j++)
    {
        if (j > 1)
        {
            printf(", ");
        }
        printf("%d", index_list[j]);
    }
    printf("] = %d\n", physical_address);
}

int main(int argc, char* argv[]) 
{
    std::cin >> N >> R;
    ReadArrays();
    for (int i = 0; i < R; i++)
    {
        QueryPhysicalAddress();
    }
    return 0;
}
