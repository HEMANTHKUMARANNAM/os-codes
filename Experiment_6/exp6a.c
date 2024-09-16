#include <stdio.h>

// Function to find the least recently used page
int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10];
    int flag1, flag2, i, j, pos, faults = 0;

    // Input number of frames and pages
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    // Input reference string
    printf("Enter reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames and time arrays
    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
        time[i] = 0;
    }

    // Process each page in the reference string
    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        // Check if page is already in any of the frames
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page is not found in frames
        if (flag1 == 0) {
            // Check for empty frame
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame is found, replace the least recently used page
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        // Print the frames
        printf("\n");
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1) {
                printf("%d\t", frames[j]);
            } else {
                printf(" \t"); // Print space for empty frames
            }
        }
    }

    // Output the total number of page faults
    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
