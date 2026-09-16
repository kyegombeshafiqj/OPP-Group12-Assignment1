 // src/percentile_rank.cpp
// Author: Tendo Malyamu
// Operation: percentile_rank()
//
// Convention used (per the Implementation Guide, Doc 2):
// Ties receive an AVERAGE rank, not a competition rank.
//   e.g. two values tied for positions 7 and 8 both get rank (7+8)/2 = 7.5
//
// Formula:
//     Percentile Rank = (rank - 1) / (n - 1) * 100
// where "rank" is the average rank described above.

#include <iostream>
using namespace std;

const int N = 10;

int scores[N] = {
    78, 92, 65, 85, 92,
    70, 55, 85, 60, 75
};

// Average rank = (count of strictly smaller elements)
//              + (count of elements equal to this one + 1) / 2
// This spreads a tied group evenly across the range of positions it occupies.
void computeAverageRanks(int arr[], int n, double ranks[]) {
    for (int i = 0; i < n; i++) {
        int countLess = 0;
        int countEqual = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] < arr[i]) countLess++;
            else if (arr[j] == arr[i]) countEqual++;
        }
        ranks[i] = countLess + (countEqual + 1) / 2.0;
    }
}

void percentileRank(int arr[], int n, double percentiles[]) {
    double ranks[N];
    computeAverageRanks(arr, n, ranks);

    for (int i = 0; i < n; i++) {
        percentiles[i] = (ranks[i] - 1) / (n - 1) * 100.0;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printPercentiles(double arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << "% ";
    cout << endl;
}

int main() {
    cout << "Original data:" << endl;
    printArray(scores, N);

    double percentiles[N];
    percentileRank(scores, N, percentiles);

    cout << "Percentile ranks (original order):" << endl;
    printPercentiles(percentiles, N);

    return 0;
}