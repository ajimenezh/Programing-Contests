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

int n,l,r,ql,qr;
int w[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>l>>r>>ql>>qr;
    for (int i=0; i<n; i++) scanf("%d",w+i);
    int sum = 0;
    for (int i=0; i<n; i++) sum += w[i]*r;
    int best = 1000000000;
    w[n] = 0;
    for (int i=0; i<=n; i++) {
        int tl = i;
        int tr = n-i;
        int cur = 0;

        if (tl==0) cur = (tr-1)*qr;
        else if (tr==0) cur = (tl-1)*ql;
        else if (tr>tl+1) cur = (tr-tl-1)*qr;
        else if (tl>tr+1) cur = (tl-tr-1)*ql;

        cur += sum;
        best = min(best, cur);
        sum -= w[i]*r;
        sum += w[i]*l;
    }

    cout<<best<<endl;

    return 0;

}
