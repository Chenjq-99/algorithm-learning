#include<iostream>
#include<vector>
using namespace std;

void Floyd(vector<vector<int>> &distances, int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX && distances[i][k] + distances[k][j] < distances[i][j])
                {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }
}