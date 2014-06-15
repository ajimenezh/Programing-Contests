#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class SixteenBricks {
	public:
	int maximumSurface(vector <int> height) ;
};

int a[4][4];

int calc() {
    int area = a[0][0] + a[3][0];
    area += a[0][1] + a[3][1];
    area += a[0][2] + a[3][2];
    area += a[0][3] + a[3][3];

    area += abs(a[1][0] - a[0][0]);
    area += abs(a[1][1] - a[0][1]);
    area += abs(a[1][2] - a[0][2]);
    area += abs(a[1][3] - a[0][3]);

    area += abs(a[2][0] - a[1][0]);
    area += abs(a[2][1] - a[1][1]);
    area += abs(a[2][2] - a[1][2]);
    area += abs(a[2][3] - a[1][3]);

    area += abs(a[3][0] - a[2][0]);
    area += abs(a[3][1] - a[2][1]);
    area += abs(a[3][2] - a[2][2]);
    area += abs(a[3][3] - a[2][3]);

}

int SixteenBricks::maximumSurface(vector <int> height) {

    sort(height.begin(), height.end());
    reverse(height.begin(), height.end());

    int n = 16;

    a[0][0] = height[0];
    a[0][1] = height[n-1];
    a[1][0] = height[n-2];
    a[0][2] = height[1];
    a[1][1] = height[2];
    a[2][0] = height[3];
    a[3][0] = height[n-3];
    a[2][1] = height[n-4];
    a[1][2] = height[n-5];
    a[0][3] = height[n-6];
    a[1][3] = height[4];
    a[2][2] = height[5];
    a[3][1] = height[6];
    a[2][3] = height[n-7];
    a[3][2] = height[n-8];
    a[3][3] = height[7];

    int area = calc();

    return area;

};

