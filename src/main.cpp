#include <iostream>
#include "../include/ranking_sorting.h"

using namespace std;

const int N = 10;

int scores[N] = {
    78, 92, 65, 85, 92,
    70, 55, 85, 60, 75
};

int main()
{
    cout << "GROUP 12 - RANKING AND SORTING\n";
    cout << "================================\n\n";

    cout << "Original data:\n";

    for (int i = 0; i < N; i++)
    {
        cout << scores[i] << " ";
    }

    cout << "\n\n";

    // Testing of the five operations will be added here.

    return 0;
}