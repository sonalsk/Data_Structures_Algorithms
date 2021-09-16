#include <bits/stdc++.h>

using namespace std;

struct Point { 
	int x, y; 
}; 

float smallestDistancePair(Point P[], int n) {
    float minVal = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float dist = sqrt(((P[j].x - P[i].x) * (P[j].x - P[i].x)) + ((P[j].y - P[i].y) * (P[j].y - P[i].y)));
            if (dist < minVal) {
                minVal = dist;
            }
        }
    }
    return minVal;
}

float smallRec(Point P[], int n, int i, int j, float minVal) {
    if (i >= n) {
        return minVal;
    }
    if (j >= n) {
        return smallRec(P, n, i + 1, i + 2, minVal);
    }
    float dist = sqrt(((P[j].x - P[i].x) * (P[j].x - P[i].x)) + ((P[j].y - P[i].y) * (P[j].y - P[i].y)));
    if (dist < minVal) {
        minVal = dist;
    }

    return smallRec(P, n, i, j + 1, minVal);
}

int main() {
    int n = 6;
    Point p[n] = {{17,6},{1,20},{15,17},{16,13},{5,6},{10,12}};
    cout << smallRec(p, n, 0, 1, INT_MAX) << endl;

    return 0;
}