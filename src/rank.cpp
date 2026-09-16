#include "../include/ranking_sorting.h"

void rankData(int scores[], double ranks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int countLess = 0;
        int countEqual = 0;

        for (int j = 0; j < n; j++)
        {
            if (scores[j] < scores[i])
                countLess++;
            else if (scores[j] == scores[i])
                countEqual++;
        }

        ranks[i] = countLess + (countEqual + 1) / 2.0;
    }
}