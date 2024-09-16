#include <stdio.h>
#include <string.h>

#define MAX_PROCESSES 20

void main() {
    int at[MAX_PROCESSES], et[MAX_PROCESSES], p[MAX_PROCESSES];
    int st[MAX_PROCESSES], ft[MAX_PROCESSES], wt[MAX_PROCESSES], ta[MAX_PROCESSES];
    int n, i, j, temp;
    char pn[MAX_PROCESSES][10], t[10];
    int totwt = 0, totta = 0;
    float awt, ata;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter process name, arrival time, execution time & priority: ");
        scanf("%s %d %d %d", pn[i], &at[i], &et[i], &p[i]);
    }

    // Sorting based on priority
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                // Swap priorities
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                // Swap arrival times
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap execution times
                temp = et[i];
                et[i] = et[j];
                et[j] = temp;

                // Swap process names
                strcpy(t, pn[i]);
                strcpy(pn[i], pn[j]);
                strcpy(pn[j], t);
            }
        }
    }

    // Calculate waiting time and turnaround time
    for (i = 0; i < n; i++) {
        if (i == 0) {
            st[i] = at[i];
        } else {
            st[i] = ft[i - 1];
        }
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + et[i];
        ta[i] = ft[i] - at[i];
        totwt += wt[i];
        totta += ta[i];
    }

    awt = (float)totwt / n;
    ata = (float)totta / n;

    // Output results
    printf("\nPname\tArrival Time\tExecution Time\tPriority\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        printf("\n%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d", pn[i], at[i], et[i], p[i], wt[i], ta[i]);
    }

    printf("\nAverage waiting time: %.2f", awt);
    printf("\nAverage turnaround time: %.2f\n", ata);
}
