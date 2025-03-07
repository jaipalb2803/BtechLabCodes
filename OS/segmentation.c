#include <stdio.h>
#include <stdlib.h>

#define MAX_SEGMENTS 10
#define MAX_SEGMENT_SIZE 256

int main()
{
    int segments[MAX_SEGMENTS][MAX_SEGMENT_SIZE];
    int segment_table[MAX_SEGMENTS];
    int logical_address, segment_number, offset, physical_address;
    int data;

    // Initialize segments with random values
    for (int i = 0; i < MAX_SEGMENTS; i++) {
        for (int j = 0; j < MAX_SEGMENT_SIZE; j++) {
            segments[i][j] = rand() % 256;
        }
    }

    // Initialize segment table
    for (int i = 0; i < MAX_SEGMENTS; i++) {
        segment_table[i] = rand() % MAX_SEGMENTS;
    }

    printf("Enter a logical address (-1 to exit): ");
    scanf("%d", &logical_address);

    while (logical_address != -1) {
        // Calculate segment number and offset
        segment_number = logical_address / MAX_SEGMENT_SIZE;
        offset = logical_address % MAX_SEGMENT_SIZE;

        // Check if segment number is valid
        if (segment_number >= MAX_SEGMENTS) {
            printf("Invalid logical address!\n");
        } else {
            // Calculate physical address using segment table
            physical_address = segment_table[segment_number] * MAX_SEGMENT_SIZE + offset;

            // Access data in physical memory
            data = segments[segment_table[segment_number]][offset];

            printf("Logical address: %d\n", logical_address);
            printf("Physical address: %d\n", physical_address);
            printf("Data at physical address: %d\n", data);
        }

        printf("\nEnter a logical address (-1 to exit): ");
        scanf("%d", &logical_address);
    }

    return 0;
}
