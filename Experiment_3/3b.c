#include <stdio.h>

struct ff {
    int pid, ser, wait;
} p[20];

int main() {
    int i, n, j, tot = 0;
    int avwait, totwait = 0, tturn = 0, aturn;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process id: ");
        scanf("%d", &p[i].pid);
        printf("Enter service time: ");
        scanf("%d", &p[i].ser);
        p[i].wait = 0;
    }

    // Sorting based on service time (Shortest Job First)
    struct ff tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].ser > p[j].ser) {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }

    // Calculate waiting times and turnaround times
    printf("PID\tSER\tWAIT\tTOT\n");
    for (i = 0; i < n; i++) {
        tot += p[i].ser;
        tturn += tot;
        if (i + 1 < n) {
            p[i + 1].wait = tot;
        }
        totwait += p[i].wait;
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].ser, p[i].wait, tot);
    }

    avwait = totwait / n;
    aturn = tturn / n;

    printf("TOTAL WAITING TIME: %d\n", totwait);
    printf("AVERAGE WAITING TIME: %d\n", avwait);
    printf("TOTAL TURNAROUND TIME: %d\n", tturn);
    printf("AVERAGE TURNAROUND TIME: %d\n", aturn);

    return 0;
}
