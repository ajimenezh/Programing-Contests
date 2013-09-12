#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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
int d[1000010];
int c2[10];
int c1[1000010][10];
long long tot[1000010][10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    long long res = 0;

    for (int i=1; i<=max(n,100); i++) {
        if (i<10) d[i] = i;
        else {
            int t = 0;
            int j = i;
            while(j>0) {
                t += j%10;
                j /= 10;
            }
            d[i] = d[t];
        }

        if (i<=n) c2[d[i]]++;

    }

    for (int i=1; i<=n; i++) for (int j=1; j*i<=n; j++) {
        if (d[i*j]!=d[d[i]*d[j]]) res++;
        if (d[i*j]==d[d[i]*d[j]]) {
            res += c2[d[i*j]];
            res--;
        }
    }

    for (int i=1; i<=n; i++) {
        c1[i][d[i]]++;
    }
    for (int j=1; j<=9; j++) c1[n+1][j] = 0;
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=9; j++) {
            c1[i][j] += c1[i+1][j];
        }
    }

    for (int j=1; j<=9; j++) tot[n+1][j] = 0;
    for (int i=n; i>=1; i--) for (int j=1; j<=9; j++) {
        for (int k=1; k<=9; k++) {
            if (d[d[i]*k]==j) {
                int t = (int)ceil(1.0*n/(1.0*i));
                if (t*i==n) t++;
                tot[i][j] += c1[t][k];
            }
        }
    }

    //for (int i=1; i<=n; i++) {
    //   for (int j=1; j<=9; j++) cout<<tot[i][j]<<" ";
        //cout<<endl;
        //cout<<i<<endl;
    //}

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=9; j++) {
            //cout<<i<<" "<<j<<" "<<tot[i][j]<<" "<<c2[j]<<endl;
            res += tot[i][j]*(long long)c2[j];
        }
    }

    cout<<res;

    return 0;

}
