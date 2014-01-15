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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
double x[101000], y[101000];
int cnt[10][10][2];
double sumx[10][10][2];
double sumy[10][10][2];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%lf%lf",x+i,y+i);
        }
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                cnt[i][j][0] = 0;
                sumx[i][j][0] = 0;
                sumy[i][j][0] = 0;

                cnt[i][j][1] = 0;
                sumx[i][j][1] = 0;
                sumy[i][j][1] = 0;
            }
        }
        for (int k=0; k<n; k++) {
            int i = (int)x[k];
            int j = (int)y[k];

            cnt[i][j][1]++;
            sumx[i][j][1] += x[k];
            sumy[i][j][1] += y[k];
        }

        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                for (int ii=0; ii<10; ii++) {
                    for (int jj=0; jj<10; jj++) {
                        if (ii>=i && jj>=j) {
                            cnt[i][j][0] += cnt[ii][jj][1];
                            sumx[i][j][0] += sumx[ii][jj][1];
                            sumy[i][j][0] += sumy[ii][jj][1];
                        }
                    }
                }
            }
        }

        double d = 0.0;
        int tot = 0;
        for (int k=0; k<n; k++) {
            int i = (int)x[k];
            int j = (int)y[k];

            d += sumx[i+1][j+1][0] + sumy[i+1][j+1][0] - cnt[i+1][j+1][0]*(x[k] + y[k]);
            tot += cnt[i+1][j+1][0];
        }

        printf("%.12lf\n",d/(double)tot);
    }

    return 0;

}
