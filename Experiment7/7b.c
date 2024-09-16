#include <stdio.h>

int main() {
    static int block_arr[10], file_arr[10];
    int fragments[10], blocks[10], files[10];
    int m, n, number_of_blocks, number_of_files, temp, lowest;

    // Initialize block_arr to zero
    for (m = 0; m < 10; m++) {
        block_arr[m] = 0;
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
        lowest = 10000; // Initialize lowest to a high value
        file_arr[m] = -1; // Initialize file_arr to -1 for unassigned files

        for (n = 0; n < number_of_blocks; n++) {
            if (block_arr[n] != 1) { // Check if block is not allocated
                temp = blocks[n] - files[m];
                if (temp >= 0 && temp < lowest) {
                    lowest = temp;
                    file_arr[m] = n;
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
    printf("\nFile Number\tBlock Number\tFile Size\tBlock Size\tFragment\n");
    for (m = 0; m < number_of_files; m++) {
        if (file_arr[m] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", m + 1, file_arr[m] + 1,
                   files[m], blocks[file_arr[m]], fragments[m]);
        } else {
            printf("%d\t\tNot Allocated\t%d\n", m + 1, files[m]);
        }
    }

    return 0;
}
