 #include "../include/ranking_sorting.h"

void percentileRankData(int scores[], double result[], int n)
{
    if (n <= 0) return;
    if (n == 1) 
    {
        result[0] = 0.0;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        int count_less = 0;
        int count_equal = 0;

        for (int j = 0; j < n; ++j)
        {
            if (scores[j] < scores[i])
            {
                count_less++;
            }
            else if (scores[j] == scores[i])
            {
                count_equal++;
            }
        }

        double rank = (count_less + 1) + (count_equal - 1) / 2.0;
        result[i] = ((rank - 1.0) / (static_cast<double>(n) - 1.0)) * 100.0;
    }
}