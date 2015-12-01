#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int n = 500;
	int A[n][n], B[n][n], multiply[n][n];

	//initialize
	int i,j;
	for (i = 0 ; i < n ; i++) {
		for (j = 0 ; j < n ; j++) {
			A[i][j] = rand();
			B[i][j] = rand();
		}
	}

	//multiply
	int c,d,k, sum=0;
	for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++) {
        for (k = 0; k < n; k++) {
          sum = sum + A[c][k]*B[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
      }
    }

	return 0;
}
