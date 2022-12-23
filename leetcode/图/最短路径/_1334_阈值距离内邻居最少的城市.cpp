#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
private:
    void dijkstra(vector<vector<long long>>& matrix, int vs, vector<long long>& dist)
    {   
        int i,j,k;
        long long min;
        int size = matrix.size();
        int flag[size];
        for (i = 0; i < size; i++)
        {
            flag[i] = 0;
            dist[i] = matrix[vs][i];
        }
        flag[vs] = 1;
        dist[vs] = 0; 
        for (i = 1; i < size; i++)
        {
            min = INT32_MAX;
            for ( j = 0; j < size; j++)
            {
                if (flag[j]==0 && dist[j]<min) 
                {
                    min = dist[j];
                    k = j;
                }
            }
            flag[k] = 1;
            for (j = 0; j < size; j++)
            {
                if (min + matrix[k][j]  < dist[j])
                {
                    dist[j] = min + matrix[k][j];
                }
            }
            
        }
    
} 
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> matrix(n, vector<long long>(n,INT32_MAX));
        for(auto edge : edges){
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }
        int city = 0;
        int minNeighbors = INT32_MAX;
        for(int i = 0; i < n; i++){
            vector<long long> dist(n,INT32_MAX);
            dijkstra(matrix,i,dist);
            int count = 0;
            for(int j = 0; j < n; j++){
                if(dist[j] <= distanceThreshold) count++;
            }
            if(count <= minNeighbors){
                minNeighbors = count;
                city = i;
            }
        }
        return city;
    }
};