/*
  SJF Algorithm when arrival time is the same for all processes
  CT = pre_CT + BT (Equation 0)
  TAT = CT - AT (Equation 1)
  TAT = BT + WT (Equation 2)

  from 1 and 2,
  BT + WT = CT - AT
  WT = CT - AT - BT (Equation 3)

  when AT = 0  //arrival time same
  WT = CT - BT (Equation 4)  //from eq 3
  TAT = CT (Equation 5)  //from eq 1

  equating 1 in 4,
  WT = pre_CT + BT - BT
  WT = pre_CT (Final Derived Equation)

  equating 1 in 5,
  TAT = pre_CT + BT (Final Derived Equation)
*/

#include <stdio.h>
#define newline puts("")
void tableBreak();
int swap(int *, int *);

int main() {
  int P[10], BT[10], TAT[10], WT[10];
  int pos, i, j, n;
  float totalTAT = 0, totalWT = 0;

  printf("Enter no. of process : ");
  scanf("%d", &n);
  puts("\nEnter Burst Time of the following processes");
  for (i = 0; i < n; i++) {
    printf("Process P[%d] : ", i + 1);
    scanf("%d", &BT[i]);
    // for initial index tracking
    P[i] = i + 1;
  }

  /* SORTING
  ----------*/
  for (i = 0; i < n; i++) {
    pos = i;
    for (j = 0; j < n; j++)
      if (BT[pos] < BT[j]) {
        pos = j;
        swap(&BT[i], &BT[pos]);
        swap(&P[i], &P[pos]);
      }
  }

  /* CALCULATION
  --------------*/
  // WT = pre_CT
  WT[0] = 0;
  for (i = 1; i < n; i++) {
    WT[i] = 0;
    for (j = 0; j < i; j++) WT[i] += BT[j];
    totalWT += WT[i];
  }

  //  TAT = BT + WT
  for (i = 0; i < n; i++) {
    TAT[i] = BT[i] + WT[i];
    totalTAT += TAT[i];
  }

  /* PRINT GRAPH
  --------------*/
  puts("\nSolution :");
  printf("0\t");
  for (i = 0; i < n; i++) printf("%d\t", TAT[i]);
  newline;
  tableBreak(n);
  for (i = 0; i < n; i++) printf("| P%d\t", P[i]);
  puts("|");
  tableBreak(n);

  /* DE-SORTING
  -------------*/
    for (i = 0; i < n; i++) {
      pos = i;
      for (j = 0; j < n; j++)
        if (P[pos] < P[j]) {
          pos = j;
          swap(&P[i], &P[pos]);
          swap(&BT[i], &BT[pos]);
          swap(&TAT[i], &TAT[pos]);
          swap(&WT[i], &WT[pos]);
        }
    }

  /* OUTPUT
  ---------*/
  newline;
  puts("Order of service (table):");
  tableBreak(4);
  puts("| P# \t| BT \t| TAT \t| WT \t|");
  tableBreak(4);
  for (i = 0; i < n; i++) {
    printf("| P%d \t", P[i]);
    printf("| %d \t", BT[i]);
    printf("| %d \t", TAT[i]);
    printf("| %d \t|\n", WT[i]);
  }
  tableBreak(4);

  newline;
  printf("Average TAT = %.2f \n", totalTAT / n);
  printf("Average WT  = %.2f \n", totalWT / n);
}
int swap(int *a, int *b) { *a = *a ^ *b ^ (*b = *a); }

void tableBreak(int n) {
  printf("+");
  for (int i = 0; i < n; i++) printf("-------+");
  newline;
}
