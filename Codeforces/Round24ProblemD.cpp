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

int n,m;
double prob[1010][1010];
pair<double,double> p[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) prob[n-1][i] = 0.0;
    if (m==1) {
        int x,y;
        cin>>x>>y;
        printf("%d\n",2*(n-x));
        return 0;
    }
    for (int i=n-2; i>=0; i--) {

        for (int j=1; j<m-1; j++) prob[i][j] = 1.0 + (1.0/4.0)*prob[i+1][j];
        prob[i][0] = 1.0 + (1.0/3.0)*prob[i+1][0];
        prob[i][m-1] = 1.0 + (1.0/3.0)*prob[i+1][m-1];

        p[0].first = 1.0 - 1.0/3.0;
        p[1].second = -1.0/3.0;
        for (int j=1; j<m-1; j++) {
            double tmp = -(-1.0/4.0) / p[j-1].first;
            p[j].first = 1.0 - 1.0/4.0 + p[j].second*tmp;
            p[j+1].second = -1.0/4.0;
            prob[i][j] += tmp*prob[i][j-1];
        }
        double tmp = -(-1.0/3.0) / p[m-2].first;
        p[m-1].first = 1.0 - 1.0/3.0 + p[m-1].second*tmp;
        prob[i][m-1] += tmp*prob[i][m-2];

        prob[i][m-1] = (prob[i][m-1])/p[m-1].first;
        for (int j=m-2; j>=0; j--) {
            prob[i][j] = (prob[i][j] - p[j+1].second*prob[i][j+1]) / p[j].first;
        }
        //for (int j=0; j<m; j++) cout<<prob[i][j]<<" "; cout<<endl;
    }

    int x,y;
    cin>>x>>y;
    x--; y--;
    printf("%.12lf\n",prob[x][y]);

    return 0;

}
