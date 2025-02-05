/*Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person wants to find a closed tour that visits each city exactly once (excelt the starting city). Find the itinerary for that person so that the total travel distance is minimal.
A solution is represented by a sequence x
1
, x
2
, . . ., x
n
  (a permutation of 1, 2, . . ., n) in which the closed tour is: x
1 
 ->  x
2
 ->  x
3
 ->  . . . ->  x
n
 ->  x
1
.
Input
Line 1: a positive integer n (1 <= n <= 1000)
Line i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)
Output
Line 1: write n 
Line 2: write the sequence of points x
1
, x
2
, . . ., x
n
(a permutation of 1, 2, . . ., n) of the itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
4
1 3 2 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n; // Number of cities
vector<vector<int>> distanceMatrix;
vector<bool> visited;
vector<int> tour;

// Greedy TSP approach
int greedyTSP(int startCity) {
    int currentCity = startCity;
    int totalDistance = 0;

    tour.push_back(currentCity + 1); // Store the starting city (1-based indexing)
    visited[currentCity] = true;

    for (int step = 1; step < n; step++) {
        int nextCity = -1;
        int minDistance = INT_MAX;

        // Find the nearest unvisited city
        for (int city = 0; city < n; city++) {
            if (!visited[city] && distanceMatrix[currentCity][city] < minDistance) {
                nextCity = city;
                minDistance = distanceMatrix[currentCity][city];
            }
        }

        // Move to the selected city
        totalDistance += minDistance;
        currentCity = nextCity;
        visited[currentCity] = true;
        tour.push_back(currentCity + 1);
    }

    // Return to the starting city
    totalDistance += distanceMatrix[currentCity][startCity];

    return totalDistance;
}

int main() {
    cin >> n;

    distanceMatrix.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distanceMatrix[i][j];
        }
    }

    int startCity = 0; // Start from city 1 (0-based indexing)
    int minimalDistance = greedyTSP(startCity);

    // Output the result
    cout << n << endl;
    for (int city : tour) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}

