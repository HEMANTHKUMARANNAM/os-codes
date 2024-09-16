#include <stdio.h>
#include <stdlib.h>  // For abs()

int main()
{
    int queue[100], head, seek = 0, n, i, j, temp, index;
    float avg;
    int t[100]; // Array to store seek times
    int visited[100] = {0}; // Array to mark visited elements

    printf("* SSTF Disk Scheduling Algorithm *\n");
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // SSTF Scheduling
    for (i = 0; i < n; i++)
    {
        t[i] = abs(head - queue[i]);
    }

    // Find the shortest seek time first
    for (i = 0; i < n; i++)
    {
        int min_seek = 10000; // A large number to initialize minimum seek time
        index = -1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && t[j] < min_seek)
            {
                min_seek = t[j];
                index = j;
            }
        }
        // Update seek time and head position
        if (index != -1)
        {
            seek += abs(head - queue[index]);
            head = queue[index];
            visited[index] = 1;
        }
    }

    printf("\nTotal Seek Time is %d\n", seek);
    avg = seek / (float)n;
    printf("Average Seek Time is %f\n", avg);

    return 0;
}
