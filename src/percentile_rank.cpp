  #include <iostream>
#include <iomanip>

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

        // Calculate fractional rank for ties
        double rank = (count_less + 1) + (count_equal - 1) / 2.0;

        // Table formula: ((Rank - 1) / (n - 1)) * 100
        result[i] = ((rank - 1.0) / (static_cast<double>(n) - 1.0)) * 100.0;
    }
}

int main()
{
    int scores[10] = {55, 60, 65, 70, 75, 78, 85, 85, 92, 92};
    double result[10];

    percentileRankData(scores, result, 10);

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Score: " << scores[i] 
                  << " -> Percentile Rank: " << result[i] << "%\n";
    }

    return 0;
}