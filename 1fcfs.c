#include <stdio.h>
#define newline puts("")
void tableBreak();

int main() {
  int BT[10], AT[10], TAT[10], WT[10], CT[10];
  int i, n, sum = 0;
  float totalTAT = 0, totalWT = 0;

  printf("Enter no. of process : ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("\nProcess P[%d]\n", i + 1);
    puts("-------------");
    printf("Enter AT : ");
    scanf("%d", &AT[i]);
    printf("Enter BT : ");
    scanf("%d", &BT[i]);
  }

  /* CALCULATION
  --------------*/
  for (i = 0; i < n; i++) {
    sum += BT[i];
    CT[i] = sum;

    TAT[i] = CT[i] - AT[i];
    totalTAT += TAT[i];

    WT[i] = TAT[i] - BT[i];
    totalWT += WT[i];
  }

  /* OUTPUT
  ---------*/
  newline;
  puts("Solution [FCFS]");
  tableBreak();
  puts("| P# \t| AT \t| BT \t| CT \t| TAT \t| WT \t|");
  tableBreak();
  for (i = 0; i < n; i++) {
    printf("| P%d \t", i + 1);
    printf("| %d \t", AT[i]);
    printf("| %d \t", BT[i]);
    printf("| %d \t", CT[i]);
    printf("| %d \t", TAT[i]);
    printf("| %d \t|\n", WT[i]);
  }
  tableBreak();

  newline;
  printf("Average TAT = %.2f \n", totalTAT / n);
  printf("Average WT  = %.2f \n", totalWT / n);
}

void tableBreak() {
  printf("+");
  for (int i = 0; i < 6; i++) printf("-------+");
  newline;
}
