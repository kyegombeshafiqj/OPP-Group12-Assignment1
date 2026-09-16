#include "../include/ranking_sorting.h"

void percentileRankData(int scores[], double result[], int n)
{
    if (n <= 0)
        return;

    // For a single value, its percentile rank is 0%
    if (n == 1)
    {
        result[0] = 0.0;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int countLess = 0;
        int countEqual = 0;

        // Find how many values are less than
        // and equal to the current value
        for (int j = 0; j < n; j++)
        {
            if (scores[j] < scores[i])
            {
                countLess++;
            }
            else if (scores[j] == scores[i])
            {
                countEqual++;
            }
        }

        // Average rank for tied values
        double rank = countLess + (countEqual + 1) / 2.0;

        // Percentile rank formula
        result[i] = ((rank - 1.0) / (n - 1.0)) * 100.0;
    }
}