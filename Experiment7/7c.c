#include <stdio.h>

int main() {
    int fragments[10], blocks[10], files[10];
    int m, n, number_of_blocks, number_of_files, temp, best_fit_index;
    static int block_arr[10], file_arr[10];
    
    // Initialize arrays
    for (m = 0; m < 10; m++) {
        block_arr[m] = 0; // 0 means block is not allocated
        file_arr[m] = -1; // -1 means file is not allocated to any block
    }

    // Input number of blocks and files
    printf("\nEnter the Total Number of Blocks:\t");
    scanf("%d", &number_of_blocks);
    printf("Enter the Total Number of Files:\t");
    scanf("%d", &number_of_files);

    // Input block sizes
    printf("\nEnter the Size of the Blocks:\n");
    for (m = 0; m < number_of_blocks; m++) {
        printf("Block No.[%d]:\t", m + 1);
        scanf("%d", &blocks[m]);
    }

    // Input file sizes
    printf("Enter the Size of the Files:\n");
    for (m = 0; m < number_of_files; m++) {
        printf("File No.[%d]:\t", m + 1);
        scanf("%d", &files[m]);
    }

    // Best Fit Allocation
    for (m = 0; m < number_of_files; m++) {
        int best_fit_size = 10000; // Initialize to a large value
        best_fit_index = -1; // Initialize to indicate no block found

        for (n = 0; n < number_of_blocks; n++) {
            if (block_arr[n] == 0) { // Check if block is not allocated
                temp = blocks[n] - files[m];
                if (temp >= 0 && temp < best_fit_size) {
                    best_fit_size = temp;
                    best_fit_index = n;
                }
            }
        }

        // Assign block if a suitable one was found
        if (best_fit_index != -1) {
            file_arr[m] = best_fit_index;
            block_arr[best_fit_index] = 1; // Mark block as allocated
            fragments[m] = best_fit_size;
        } else {
            file_arr[m] = -1; // Indicate no block found
            fragments[m] = -1; // Indicate no fragment
        }
    }

    // Output the results
    printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment\n");
    for (m = 0; m < number_of_files; m++) {
        if (file_arr[m] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", m + 1, files[m],
                   file_arr[m] + 1, blocks[file_arr[m]], fragments[m]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t-\t\t-\n", m + 1, files[m]);
        }
    }

    return 0;
}
