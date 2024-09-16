#include <stdio.h>

int main() {
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;

    // Input number of pages
    printf("\nENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);

    // Input page numbers
    printf("\nENTER THE PAGE NUMBERS:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input number of frames
    printf("\nENTER THE NUMBER OF FRAMES:\n");
    scanf("%d", &no);

    // Initialize frames to -1
    for (i = 0; i < no; i++) {
        frame[i] = -1;
    }

    // FIFO page replacement algorithm
    j = 0;
    printf("\tRef String\tPage Frames\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", a[i]);
        avail = 0;

        // Check if page is already in one of the frames
        for (k = 0; k < no; k++) {
            if (frame[k] == a[i]) {
                avail = 1;
                break;
            }
        }

        // If page is not available in frames, replace and update frame
        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no; // Move to the next frame position in a circular manner
            count++;
        }

        // Print current state of frames
        for (k = 0; k < no; k++) {
            if (frame[k] != -1) {
                printf("%d\t", frame[k]);
            } else {
                printf("-\t"); // Print '-' for empty frames
            }
        }
        printf("\n");
    }

    // Output the number of page faults
    printf("Page Faults: %d\n", count);
    return 0;
}
