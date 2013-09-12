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

int n,a[100010],k,len;
int b[100010];
pair<int,int> v[300000];
long long res;
bool changed[100010];
set<pair<int,int> > q;

void update(int id, int l, int r, int lt, int rt, int val) {
    if (l>rt || r<lt) return;
    if (l==r && l==lt) {
        v[id] = make_pair(val,lt);
        return;
    }
    int h = (l+r)/2;
    update(2*id,l,h,lt,rt,val);
    update(2*id+1,h+1,r,lt,rt,val);
    if (v[2*id].first<v[2*id+1].first) {
        v[id] = v[2*id];
    }
    else {
        v[id] = v[2*id+1];
    }
    return;
}

long long solve() {
    long long sol = 0;
    int f = 0;
    for (int i=0; i<n; i++) b[i] = a[i];
    for (int i=0; i<300000; i++) v[i] = make_pair(0,-1);
    for (int i=0; i<len; i++) update(1,1,n,i+1,i+1,b[i]);
    for (int i=0; i<n; i++) changed[i] = 0;

    int c = k;
    long long sum = 0;
    for (int i=0; i<len; i++) sum += b[i];
    for (int i=0; i<=n-len; i++) {
        if (i!=0) {
            if (changed[i-1]) {
                q.erase(make_pair(b[i-1],i-1));
                sum -= b[i-1];
                c++;
                update(1,1,n,i,i,0);
                update(1,1,n,i+len,i+len,b[i+len-1]);
                sum += b[i+len-1];
            }
            else {
                sum -= b[i-1];
                update(1,1,n,i+len,i+len,b[i+len-1]);
                update(1,1,n,i,i,0);
                sum += b[i+len-1];
            }
            int last = -1;
            if (q.size()>0) last = (*q.begin()).second;
            if (last>=0 && abs(b[last])<abs(b[i+len-1]) && b[i+len-1]<0) {
                sum = sum - 2LL*b[last] - 2LL*b[i+len-1];
                b[i+len-1] = -b[i+len-1];
                update(1,1,n,i+len,i+len,b[i+len-1]);
                changed[i+len-1] = 1;
                q.insert(make_pair(b[i+len-1],i+len-1));

                q.erase(make_pair(b[last],last));
                b[last] = -b[last];
                update(1,1,n,last+1,last+1,b[last]);
                changed[last] = 0;
            }
        }
        //cout<<v[1].first<<endl;
        while (v[1].first<0 && c>0) {
            c--;
            b[v[1].second-1] = -v[1].first;
            changed[v[1].second-1] = 1;
            q.insert(make_pair(b[v[1].second-1],v[1].second-1));
            sum = sum + 2LL*b[v[1].second-1];
            update(1,1,n,v[1].second,v[1].second,b[v[1].second-1]);
        }
        sol = max(sol,abs(sum));//cout<<i<<" "<<sum<<endl;
    }
    return sol;

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>len;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    cin>>k;
    res = solve();
    for (int i=0; i<n; i++) a[i] = -a[i];
    res = max(res,solve());
    cout<<res;

    return 0;

}
