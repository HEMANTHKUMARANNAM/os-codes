#include <stdio.h>

int main() {
    int fragments[10], block[10], file[10];
    int m, n, number_of_blocks, number_of_files;
    int temp, lowest;
    static int block_arr[10], file_arr[10];

    // Initialize block_arr to zero
    for (m = 0; m < 10; m++) {
        block_arr[m] = 0;
    }

    // Input number of blocks and files
    printf("\nEnter the Total Number of Blocks:\t");
    scanf("%d", &number_of_blocks);
    printf("\nEnter the Total Number of Files:\t");
    scanf("%d", &number_of_files);

    // Input block sizes
    printf("\nEnter the Size of the Blocks:\n");
    for (m = 0; m < number_of_blocks; m++) {
        printf("Block No.[%d]:\t", m + 1);
        scanf("%d", &block[m]);
    }

    // Input file sizes
    printf("Enter the Size of the Files:\n");
    for (m = 0; m < number_of_files; m++) {
        printf("File No.[%d]:\t", m + 1);
        scanf("%d", &file[m]);
    }

    // Best Fit Allocation
    for (m = 0; m < number_of_files; m++) {
        lowest = 10000;
        file_arr[m] = -1; // Initialize file_arr to -1 for unassigned files

        for (n = 0; n < number_of_blocks; n++) {
            if (block_arr[n] != 1) { // Check if block is not allocated
                temp = block[n] - file[m];
                if (temp >= 0 && temp < lowest) {
                    file_arr[m] = n;
                    lowest = temp;
                }
            }
        }

        // Assign block and mark it as allocated
        if (file_arr[m] != -1) {
            block_arr[file_arr[m]] = 1;
            fragments[m] = lowest;
        } else {
            fragments[m] = -1; // Indicate no block found
        }
    }

    // Output the results
    printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment\n");
    for (m = 0; m < number_of_files; m++) {
        if (file_arr[m] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", m + 1, file[m], file_arr[m] + 1,
                   block[file_arr[m]], fragments[m]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", m + 1, file[m]);
        }
    }

    return 0;
}
