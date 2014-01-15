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
int num[100010];
map<int,int> ind;
long long sum[320][5];
int op[100010];
set<int> all[320];

void update(int c, int s) {
    int k = ind[abs(c)];
    int i = k/s;

    if (c>0) all[i].insert(c);
    else all[i].erase(-c);

    for (int t=0; t<5; t++) sum[i][t] = 0;

    int t = 0;

    rep(it,all[i]) {
        sum[i][t] += *it;
        t++;
        if (t>=5) t-=5;
    }

}


long long get() {
    int s = (int)sqrt(n);
    int t = 2;
    long long res = 0;
    for (int i=0; i*i<n; i++) {
        res += sum[i][t];
        t -= all[i].size()%5;
        if (t<0) t += 5;
    }
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d",&n)!=EOF) {
        int m = 0;
        for (int i=0; i<n; i++) {
            string s;
            cin>>s;
            if (s[0]=='a') {
                int c;
                cin>>c;
                op[i] = c;
                num[m++] = c;
            }
            else if (s[0]=='d') {
                int c;
                cin>>c;
                op[i] = -c;
                num[m++] = c;
            }
            else {
                op[i] = 0;
            }
        }
        sort(num,num+m);
        int tmp = 0;
        for (int i=0; i<m; i++) {
            if (i==0 || num[i]!=num[i-1]) num[tmp++] = num[i];
        }
        m = tmp;
        for (int i=0; i<m; i++) ind[num[i]] = i;
        int s = (int)sqrt(n);
        for (int i=0; i*i<n; i++) {
            all[i].clear();
            for (int j=0; j<5; j++) sum[i][j] = 0;
        }
        for (int i=0; i<n; i++) {
            if (op[i]!=0) {
                update(op[i],s);
                //cout<<i<<" "; printf("%I64d\n",get());
            }
            else {
                printf("%I64d\n",get());
            }
        }
    }

    return 0;

}
