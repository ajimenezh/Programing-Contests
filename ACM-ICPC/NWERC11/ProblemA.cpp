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

int t;
long long m;
vector<pair<long long, long long> > v;
long long c[1001][1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>m;
        v.clear();
        v.push_back(make_pair(m,1));
        v.push_back(make_pair(m,m-1));

        long long delta = 1 + 8*m;
        if ((int)sqrt(delta)*sqrt(delta)==delta) {
            if (((int)sqrt(delta)+1)%2==0) {
                int n = ((int)sqrt(delta)+1)/2;
                v.push_back(make_pair(n,2));
                v.push_back(make_pair(n,n-2));
            }
        }

        for (int i=3; (long long)i*(i-1)*(i-2)<=6*m; i++) {
            long long t = i*(i-1)*(i-2);
            if (t%6!=0) continue;
            if (t/6==m) {
                v.push_back(make_pair(i,3));
                v.push_back(make_pair(i,i-3));
                break;
            }
        }

        for (int i=4; (long long)i*(i-1)*(i-2)*(i-3)<=24*m; i++) {
            long long t = i*(i-1)*(i-2)*(i-3);
            if (t%24!=0) continue;
            if (t/24==m) {
                v.push_back(make_pair(i,4));
                v.push_back(make_pair(i,i-4));
                break;
            }
        }

        for (int i=0; i<=1000; i++) {
            c[i][0] = 1;
            c[i][i] = 1;
            for (int j=1; j<i; j++) {
                c[i][j] = c[i-1][j] + c[i-1][j-1];
                if (c[i][j]>m) c[i][j] = m+1;
                if (c[i][j]==m && j>=4 && i-j>=4) {
                    v.push_back(make_pair(i,j));
                    v.push_back(make_pair(i,i-j));
                }
            }
        }

        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        cout<<v.size()<<"\n";
        for (int i=0; i<v.size(); i++) {
            cout<<"("<<v[i].first<<","<<v[i].second<<") ";
        }
        printf("\n");
    }

    return 0;

}
