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
pair<int,int> v[100010];
int p[100010];

bool cmp(int i, int j) {
    return v[i].first+v[i].second<v[j].first+v[j].second;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            int w,s;
            scanf("%d%d",&w,&s);
            v[i] = make_pair(w,s);
            p[i] = i;
        }
        sort(p,p+n,cmp);
        __int64 sum = 0;
        __int64 m = 0;
        for (int i=0; i<n; i++) {
            m = max(sum-v[p[i]].second,m);
            sum += v[p[i]].first;
        }
        cout<<m<<endl;
    }

    return 0;

}
