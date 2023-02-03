#include <stdio.h>

void main() {
  int i, n, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10],
            temp[10];
  float avg_wt, avg_tat;
  printf(" Total number of process in the system: ");
  scanf("%d", &n);
  y = n;
  printf("\nEnter the AT and BT of the following\n");
  for (i = 0; i < n; i++) {
    printf("\nProcess[%d]\n", i + 1);
    printf("AT : ");
    scanf("%d", &at[i]);
    printf("BT : ");
    scanf("%d", &bt[i]);
    temp[i] = bt[i];
  }
  printf("\nEnter the Time Quantum for the process : ");
  scanf("%d", &quant);
  printf("\nP[#]\t BT\t TAT\t WT ");
  for (sum = 0, i = 0; y != 0;) {
    if (temp[i] <= quant && temp[i] > 0) {
      sum = sum + temp[i];
      temp[i] = 0;
      count = 1;
    } else if (temp[i] > 0) {
      temp[i] = temp[i] - quant;
      sum = sum + quant;
    }
    if (temp[i] == 0 && count == 1) {
      y--;
      printf("\nP[%d]\t %d\t %d\t %d", i + 1, bt[i], sum - at[i],
             sum - at[i] - bt[i]);
      wt = wt + sum - at[i] - bt[i];
      tat = tat + sum - at[i];
      count = 0;
    }
    if (i == n - 1) {
      i = 0;
    } else if (at[i + 1] <= sum) {
      i++;
    } else {
      i = 0;
    }
  }
  avg_wt = wt * 1.0 / n;
  avg_tat = tat * 1.0 / n;
  printf("\nAverage Turn Around Time: %f", avg_wt);
  printf("\nAverage Waiting Time: %f\n", avg_tat);
}
