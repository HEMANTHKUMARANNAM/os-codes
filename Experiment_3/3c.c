#include <stdio.h>

struct roundRobin {
    int pburst, pburst1, wtime, endtime, arrivt, boolean, flagcntl;
    char pname[5];
} a[5];

int n, tq;

void input();
void initialize();
void calculate();
void display_waittime();

int main() {
    input();
    initialize();
    calculate();
    display_waittime();
    return 0;
}

void input() {
    int i;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter process name: ");
        scanf("%s", a[i].pname);
        printf("Enter process burst time: ");
        scanf("%d", &a[i].pburst);
        printf("Enter process arrival time: ");
        scanf("%d", &a[i].arrivt);
    }

    printf("\nEnter the time quantum/Time Slice: ");
    scanf("%d", &tq);
}

void initialize() {
    int i;
    for (i = 0; i < n; i++) {
        a[i].pburst1 = a[i].pburst;
        a[i].wtime = 0;
        a[i].endtime = 0;
        a[i].boolean = 0;
        a[i].flagcntl = 0;
    }
}

void calculate() {
    int i, j = 0, k = 0, flag = 1, count = 0;
    printf("\n---GANTT CHART---\n");
    printf("0 | ");

    while (flag) {
        for (i = 0; i < n; i++) {
            if ((k < n) && (a[i].arrivt <= count) && (a[i].flagcntl == 0)) {
                // Calculating waiting time for the first time
                a[i].wtime = count - a[i].arrivt;
                a[i].endtime = count;
                a[i].boolean = 1;
                a[i].flagcntl = 1;
                k++;
            }
            
            if ((a[i].pburst1 > tq) && (a[i].arrivt <= count)) {
                if (a[i].boolean == 1)
                    a[i].boolean = 0;
                else
                    a[i].wtime += (count - a[i].endtime);
                
                count += tq;
                a[i].pburst1 -= tq;
                a[i].endtime = count;
                printf("%d %s| ", count, a[i].pname);
            } 
            else if ((a[i].pburst1 > 0) && (a[i].pburst1 <= tq) && (a[i].arrivt <= count)) {
                if (a[i].boolean == 1)
                    a[i].boolean = 0;
                else
                    a[i].wtime += (count - a[i].endtime);
                
                count += a[i].pburst1;
                a[i].endtime = count;
                printf("%d %s| ", count, a[i].pname);
                a[i].pburst1 = 0;
                j++;
            }
        }

        // Check if all processes are completed
        if (j == n) {
            flag = 0;
        }
    }
}

void display_waittime() {
    int i, tot = 0, turn = 0;
    for (i = 0; i < n; i++) {
        printf("\nWaiting time for Process %s is %d", a[i].pname, a[i].wtime);
        tot += a[i].wtime;
        turn += a[i].endtime - a[i].arrivt;
    }
    
    printf("\nAverage waiting time = %.2f", (float) tot / n);
    printf("\nAverage turnaround time = %.2f\n", (float) turn / n);
}
