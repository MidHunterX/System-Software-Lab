#include <stdio.h>
void sort();
void swap(int *a, int *b);
void WT_TAT(int *a, int *b);

int P[30], BT[30], tot_TAT = 0, pr[30], WT[30], n, tot_WT = 0, TAT[30],
                   PR_wt = 0, PR_tat = 0;
float awt, avg_tat, avg_wt;

void main() {
  int i;
  printf("\nEnter the No.of processes : ");
  scanf("%d", &n);
  printf("\nEnter burst time and priority of following");
  for (i = 0; i < n; i++) {
    printf("\nProcess[%d]", i + 1);
    printf("\nBT : ");
    scanf("%d", &BT[i]);
    printf("Priority : ");
    scanf("%d", &pr[i]);
    P[i] = i;
  }
  sort();
  WT_TAT(&PR_tat, &PR_wt);
  printf("\nAverage WT : %d", PR_wt / n);
  printf("\nAverage TAT : %d \n", PR_tat / n);
}

void sort() {
  int t, i, j, t2, t1;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (pr[i] > pr[j]) {
        swap(&BT[j], &BT[i]);
        swap(&P[j], &P[i]);
        swap(&pr[j], &pr[i]);
      }
    }
  }
}
void swap(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}
void WT_TAT(int *a, int *b) {
  int i;
  for (i = 0; i < n; i++) {
    if (i == 0)
      TAT[i] = BT[i];
    else
      TAT[i] = TAT[i - 1] + BT[i];
    tot_TAT = tot_TAT + TAT[i];
  }
  *a = tot_TAT;
  WT[0] = 0;
  for (i = 1; i < n; i++) {
    WT[i] = WT[i - 1] + BT[i - 1];
    tot_WT = tot_WT + WT[i];
  }
  *b = tot_WT;

  printf("\nPID\tBT\tPRIORITY\tTAT\tWT");
  for (i = 0; i < n; i++)
    printf("\nP[%d]\t%d\t\t%d\t%d\t%d", P[i] + 1, BT[i], pr[i], TAT[i], WT[i]);
}
