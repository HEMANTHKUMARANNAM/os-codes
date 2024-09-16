#include <stdio.h>
#include <stdlib.h>  // For abs()

int main()
{
    int queue[20], n, head, i, j, k, seek = 0, max, diff;
    int queue1[20], queue2[20];
    int temp, temp1 = 0, temp2 = 0;
    float avg;

    printf("Enter the max range of disk: ");
    scanf("%d", &max);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the size of queue request: ");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read: \n");
    for (i = 0; i < n; i++)  // Note: Start from 0 to n-1
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }

    // Sort queue1 in ascending order
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    // Sort queue2 in descending order
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] < queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    // Merge queues
    for (i = 0; i < temp1; i++)
        queue[i] = queue1[i];
    queue[temp1] = max;
    for (i = temp1 + 1, j = 0; j < temp2; i++, j++)
        queue[i] = queue2[j];
    queue[i] = 0;  // Append 0 at the end
    queue[0] = head;  // Set initial head position at the start

    // Calculate seek time
    for (j = 0; j < n + 2; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
    }

    printf("Total seek time is %d\n", seek);
    avg = seek / (float)n;
    printf("Average seek time is %f\n", avg);

    return 0;
}
