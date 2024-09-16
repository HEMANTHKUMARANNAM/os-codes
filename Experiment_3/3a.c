#include <stdio.h>

struct process {
    int id, wait, ser, tottime;
} p[20];

int main() {
    int i, n, j;
    int totalwait = 0, totalser = 0;
    float avturn, avwait;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process_id: ");
        scanf("%d", &p[i].id);
        printf("Enter process service time: ");
        scanf("%d", &p[i].ser);
    }

    p[0].wait = 0;
    p[0].tottime = p[0].ser;

    for (i = 1; i < n; i++) {
        p[i].wait = 0;
        for (j = 0; j < i; j++) {
            p[i].wait += p[j].ser;
        }
        totalwait += p[i].wait;
        p[i].tottime = p[i].wait + p[i].ser;
        totalser += p[i].tottime;
    }

    avturn = (float) totalser / n;
    avwait = (float) totalwait / n;

    printf("Id\tService\tWait\tTotal\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].ser, p[i].wait, p[i].tottime);
    }

    printf("Average waiting time: %.2f\n", avwait);
    printf("Average turnaround time: %.2f\n", avturn);

    return 0;
}
