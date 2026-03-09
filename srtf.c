#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    char pid[20][10];
    int at[20], bt[20], rt[20];
    int wt[20], tat[20];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0;
    int min_rt, shortest = -1;
    int finish_time;

    while (complete < n) {

        min_rt = 100000;
        shortest = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;

        if (rt[shortest] == 0) {
            complete++;

            finish_time = time + 1;

            wt[shortest] = finish_time - bt[shortest] - at[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;

            tat[shortest] = bt[shortest] + wt[shortest];
        }

        time++;
    }

    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
