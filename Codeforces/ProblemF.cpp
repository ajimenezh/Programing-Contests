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

const double eps = 1.0e-8;

int n,t;
double p[55][3];
int v[55];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n>>t;
        for (int i=1; i<=n; i++) {
            string s;
            cin>>s;
            if (s=="0") v[i] = 0;
            else if (s=="L") v[i] = 1000;
            else {
                v[i] = atoi(s.substr(1,s.length()-1).c_str());
                if (s[0]=='-') v[i] = -v[i];
            }
        }
        v[0] = 0;
        v[n+1] = 0;
        for (int i=0; i<n+2; i++) p[i][1] = 0.0;
        for (int j=0; j<n+2; j++) p[j][2] = 0.0;
        p[0][1] = 1.0;

        double total = 0.0;
        for (int i=0; i<t; i++) {
            for (int j=0; j<n+2; j++) p[j][i%2] = 0.0;
            for (int j=0; j<n+1; j++) {
                p[j][i%2] += p[j][2];
            }
            for (int j=0; j<n+2; j++) p[j][2] = 0.0;
            for (int j=0; j<n+1; j++) {
                if (j==n) {
                    p[j+1][i%2] += p[j][1-i%2];
                }
                else {
                    if (v[j+1]==0) {
                        p[j+1][i%2] += 0.5*p[j][1-i%2];
                    }
                    else if (v[j+1]==1000) {
                        p[j+1][2] += 0.5*p[j][1-i%2];
                    }
                    else {
                        p[j+1+v[j+1]][i%2] += 0.5*p[j][1-i%2];
                    }

                    if (v[j+2]==0) {
                        p[j+2][i%2] += 0.5*p[j][1-i%2];
                    }
                    else if (v[j+2]==1000) {
                        p[j+2][2] += 0.5*p[j][1-i%2];
                    }
                    else {
                        p[j+2+v[j+2]][i%2] += 0.5*p[j][1-i%2];
                    }
                }
            }
            //for (int j=0; j<n+2; j++) cout<<p[j][i%2]<<" "; cout<<endl;
            total += p[n+1][i%2];
        }

        if (total>0.5+eps) cout<<"Bet for. ";
        else if (total<0.5-eps) cout<<"Bet against. ";
        else cout<<"Push. ";
        printf("%.4lf\n",round(total*10000.0)/10000.0);
    }

    return 0;

}

