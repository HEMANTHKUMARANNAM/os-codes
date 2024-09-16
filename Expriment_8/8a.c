#include <stdio.h>
#include <stdlib.h>  // For abs()

int main()
{
    int queue[20], n, head, i, j, seek = 0, max, diff;
    float avg;

    // Input max range of disk and size of queue request
    printf("Enter the max range of disk: ");
    scanf("%d", &max);
    printf("Enter the size of queue request: ");
    scanf("%d", &n);

    // Input queue of disk positions
    printf("Enter the queue of disk positions to be read:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    // Input initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Add the initial head position to the beginning of the queue
    for (i = n; i > 0; i--)
    {
        queue[i] = queue[i - 1];
    }
    queue[0] = head;
    n++;

    // Calculate the seek time
    printf("Disk head moves:\n");
    for (j = 0; j < n - 1; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("From %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
    }

    // Print total seek time and average seek time
    printf("Total seek time is %d\n", seek);
    avg = seek / (float)(n - 1);  // (n-1) because we have n-1 movements
    printf("Average seek time is %f\n", avg);

    return 0;
}
