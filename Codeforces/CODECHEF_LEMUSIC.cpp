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
pair<int,int> v1[100010];
pair<int,int> v2[100010];
long long total;
long long dif;
long long res;
bool vis[100010];
int a,b;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t = 0; t<tt; t++) {
        scanf("%d",&n);

        for (int i=0; i<n; i++) {
            scanf("%d%d",&a,&b);
            v1[i] = make_pair(a,b);
        }
        sort(v1,v1+n);
        int cnt = 0;
        int tmp = -1;
        for (int i=0; i<n; i++) {
            if (i==0) {
                tmp = v1[i].first;
                v1[i].first = cnt++;
            }
            else {
                if (v1[i].first!=tmp) {
                    tmp = v1[i].first;
                    v1[i].first = cnt++;
                }
                else {
                    v1[i].first = cnt-1;
                }
            }
        }
        for (int i=0; i<cnt; i++) vis[i] = 0;
        for (int i=0; i<n; i++) v2[i] = make_pair(v1[i].second,v1[i].first);
        sort(v2,v2+n);

        total = 0;
        res = 0;
        dif = 0;

        for (int i=0; i<n; i++) {
            if (!vis[v2[i].second]) {
                vis[v2[i].second] = 1;
                dif++;
                res += (long long)dif*(long long)v2[i].first;
            }
            else {
                total += v2[i].first;
            }
        }

        //cout<<total<<" "<<dif<<endl;

        res += total*(long long)dif;

        printf("%I64d\n",res);
    }

    return 0;

}
