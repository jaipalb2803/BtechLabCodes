#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 256
#define MEMORY_SIZE 4096
#define NUM_PAGES (MEMORY_SIZE / PAGE_SIZE)

int main()
{
    int memory[MEMORY_SIZE];
    int page_table[NUM_PAGES];
    int logical_address, page_number, offset, physical_address;
    int data;

    // Initialize memory with random values
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = rand() % 256;
    }

    // Initialize page table
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = rand() % NUM_PAGES;
    }

    printf("Enter a logical address (-1 to exit): ");
    scanf("%d", &logical_address);

    while (logical_address != -1) {
        // Calculate page number and offset
        page_number = logical_address / PAGE_SIZE;
        offset = logical_address % PAGE_SIZE;

        // Check if page number is valid
        if (page_number >= NUM_PAGES) {
            printf("Invalid logical address!\n");
        } else {
            // Calculate physical address using page table
            physical_address = page_table[page_number] * PAGE_SIZE + offset;

            // Access data in physical memory
            data = memory[physical_address];

            printf("Logical address: %d\n", logical_address);
            printf("Physical address: %d\n", physical_address);
            printf("Data at physical address: %d\n", data);
        }

        printf("\nEnter a logical address (-1 to exit): ");
        scanf("%d", &logical_address);
    }

    return 0;
}
