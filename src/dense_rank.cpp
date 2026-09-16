// Group 12 - dense_rank() implementation

#include "../include/ranking_sorting.h"

void denseRankData(int scores[], int ranks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int rank = 1;

        for (int j = 0; j < n; j++)
        {
            if (scores[j] < scores[i])
            {
                bool alreadyCounted = false;

                for (int k = 0; k < j; k++)
                {
                    if (scores[k] == scores[j])
                    {
                        alreadyCounted = true;
                        break;
                    }
                }

                if (!alreadyCounted)
                {
                    rank++;
                }
            }
        }

        ranks[i] = rank;
    }
}