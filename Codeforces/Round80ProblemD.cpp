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

int a[300010];
int n,q;
pair<int,int> v[300010];
int m;
long long sum[550][550];
long long res[300010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    cin>>q;
    for (int i=0; i<q; i++) scanf("%d%d",&v[i].first,&v[i].second);
    for (int i=0; i<q; i++) v[i].first--;
    m = 548;
    for (int i=0; i<q; i++) res[i] = 0;

    for (int i=0; i<=n/m; i++) {
        if (i*m>=n) break;

        for (int j=0; j<q; j++) {
            if (v[j].first<i*m && v[j].first+v[j].second<m*(i+1)) {
                int c = v[j].first;
                int b = v[j].second;
                int k = (i*m-c)/b;
                c = c + k*b;
                while (c<i*m) c += b;
                v[j].first = c;
            }
            else if (v[j].first<i*m) v[j].first += v[j].second;
            //cout<<v[j].first<<" "<<v[j].second<<endl;
        }

        for (int j=m*(i+1)-1; j>=m*(i); j--) {
            if (j>=n) continue;
            sum[j-m*i][0] = (long long)a[j];
            for (int k=1; k<=m; k++) {
                sum[j-m*i][k] = sum[j-m*i][0];
                if (j+k<m*(i+1) && j+k<n) {
                    sum[j-m*i][k] += sum[j+k-m*i][k];
                    //cout<<j<<" "<<k<<" "<<sum[j-m*i][k]<<endl;
                }
            }
        }
        for (int j=0; j<q; j++) {
            if (v[j].first<min(m*(i+1),n) && v[j].second<=m) res[j] += sum[v[j].first-m*i][v[j].second];
            else if (v[j].first<min(m*(i+1),n) && v[j].second>m) res[j] += sum[v[j].first-m*i][0];
        }
    }
    for (int i=0; i<q; i++) printf("%I64d\n",res[i]);

    return 0;

}
