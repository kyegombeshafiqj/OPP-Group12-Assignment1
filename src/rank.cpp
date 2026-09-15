//Group 12 - rank() implementation
void rankData(const int scores[], int ranks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int r = 1;

        for (int j = 0; j < n; j++)
        {
            if (scores[j] < scores[i])
            {
                r++;
            }
        }

        ranks[i] = r;
    }
}
