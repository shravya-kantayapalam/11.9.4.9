#include <stdio.h>
#include <math.h>

// Function to calculate the nth term of the series
int nthTerm(int n) {
    return (pow(n, 2) + pow(2, n));
}

// Function to calculate the sum of the series up to n terms
int sumOfSeries(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += nthTerm(i);
    }
    return sum;
}

int main() {
    FILE *fp;
    fp = fopen("sums.dat", "w"); // Open file for writing
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    printf("Enter the maximum value of n: ");
    scanf("%d", &n);

    // Print the sum of the series for values of n from 1 to the maximum value
    fprintf(fp, "# n\tSum\n"); // Header for .dat file
    for (int i = 1; i <= n; i++) {
        int sum = sumOfSeries(i);
        fprintf(fp, "%d\t%d\n", i, sum);
    }

    fclose(fp); // Close the file

    printf("Data has been written to sums.dat\n");

    return 0;
}

