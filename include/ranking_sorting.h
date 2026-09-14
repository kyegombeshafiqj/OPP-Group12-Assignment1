#ifndef RANKING_SORTING_H
#define RANKING_SORTING_H

void sortData(int scores[], int n);

void argsortData(int scores[], int indices[], int n);

void rankData(int scores[], double ranks[], int n);

void denseRankData(int scores[], int ranks[], int n);

void percentileRankData(int scores[], double result[], int n);

#endif