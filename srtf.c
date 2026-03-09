#include <stdio.h>

int main() {
    int n, i, time = 0, smallest;
    int completed = 0;
    int arrival[20], burst[20], remaining[20];
    int waiting[20], turnaround[20];
    int finish_time;
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);

        remaining[i] = burst[i];
    }

    remaining[19] = 9999; // sentinel value

    while(completed != n) {

        smallest = 19;

        for(i = 0; i < n; i++) {
            if(arrival[i] <= time && remaining[i] < remaining[smallest] && remaining[i] > 0) {
                smallest = i;
            }
        }

        remaining[smallest]--;

        if(remaining[smallest] == 0) {
            completed++;

            finish_time = time + 1;

            waiting[smallest] = finish_time - burst[smallest] - arrival[smallest];
            turnaround[smallest] = finish_time - arrival[smallest];

            total_wt += waiting[smallest];
            total_tat += turnaround[smallest];
        }

        time++;
    }

    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i+1, arrival[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat/n);

    return 0;
}
