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

int n,k;
int a[210];
int suml[210][11];
int sumr[210][11];
int sumlr[210][210][11];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }


    for (int i=0; i<=k; i++) {
        set<int> s;
        for (int j=0; j<n; j++) {
            s.insert(-a[j]);
            set<int>::iterator it = s.begin();
            int t = i;
            while (it!=s.end() && t>0) {
                suml[j][i] -= (*it);
                it++;
                t--;
            }
        }
        s.clear();
        for (int j=n-1; j>=0; j--) {
            s.insert(-a[j]);
            set<int>::iterator it = s.begin();
            int t = i;
            while (it!=s.end() && t>0) {
                sumr[j][i] -= (*it);
                it++;
                t--;
            }
        }
    }

    for (int i=0; i<n; i++) {
        sumlr[i][i][0] = a[i];
        for (int j=i+1; j<n; j++) {
            sumlr[i][j][0] = a[j] + sumlr[i][j-1][0];
        }
    }

    for (int t=1; t<=k; t++) {
        for (int i=0; i<n; i++) {
            set<int> s;
            s.insert(a[i]);
            sumlr[i][i][t] = a[i];
            for (int j=i+1; j<n; j++) {
                s.insert(a[j]);
                sumlr[i][j][t] = sumlr[i][j][0];

                int r = t;
                set<int>::iterator it = s.begin();
                while (r>0 && it!=s.end()) {
                    sumlr[i][j][t] -= (*it);
                    it++;
                    r--;
                }
            }
        }
    }


    int best = -2000000;

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            for (int t=0; t<=k; t++) {
                for (int r=0; r<=t; r++) {
                    if (i!=0)
                        best = max(best, sumlr[i][j][t] + suml[i-1][r] + sumr[j+1][t-r]);
                    else
                        best = max(best, sumlr[i][j][t] + sumr[j+1][t-r]);
                }
            }
        }
    }

    cout<<best<<endl;


    return 0;

}
