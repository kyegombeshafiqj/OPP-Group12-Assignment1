//Group 12 - percentile_rank() implementation
#include <iostream>
#include <vector>

void percentileRankData(const std::vector<int>& scores, std::vector<double>& result)
{
    const std::size_t n = scores.size();
    result.resize(n);

    if (n == 0) return;
    if (n == 1) 
    {
        result[0] = 0.0;
        return;
    }

    for (std::size_t i = 0; i < n; ++i)
    {
        int count_less = 0;
        int count_equal = 0;

        for (std::size_t j = 0; j < n; ++j)
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

        // Calculate fractional rank (e.g., ties at 7 and 8 get rank 7.5)
        double rank = (count_less + 1) + (count_equal - 1) / 2.0;

        // Formula: ((Rank - 1) / (n - 1)) * 100
        result[i] = ((rank - 1.0) / (static_cast<double>(n) - 1.0)) * 100.0;
    }
}

int main()
{
    // Scores matching the table image
    std::vector<int> scores = {55, 60, 65, 70, 75, 78, 85, 85, 92, 92};
    std::vector<double> percentiles;

    percentileRankData(scores, percentiles);

    std::cout.precision(2);
    std::cout << std::fixed;

    for (std::size_t i = 0; i < scores.size(); ++i)
    {
        std::cout << "Score: " << scores[i] 
                  << " -> Percentile Rank: " << percentiles[i] << "%\n";
    }

    return 0;
}