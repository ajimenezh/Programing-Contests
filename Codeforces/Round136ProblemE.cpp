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
long long k;
int a[100010];
map<int,int> m;
int v[100010];
int f;
long long tot;
long long b[100010];
bool vis[100010];

int ask(int c) {
    if (c<=0) return 0;
    int s = 0;
    for (int i=c; i>0; i -= i & -i) s += v[i];
    return s;
}

int query(int c, int d) {
    if (c<d) return query(d,c);
    return ask(c) - ask(d-1);
}

void update(int c, int val) {
    for (int i=c; i<=f; i += i & -i) v[i] += val;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) m[a[i]] = 0;
    rep(it,m) (*it).second = ++f; f++;
    for (int i=0; i<n; i++) a[i] = m[a[i]];
    for (int i=0; i<n; i++) {
        tot += query(f,a[i]+1);
        b[i] = query(f,a[i]+1);
        update(a[i],1);
    }//for (int i=0; i<n; i++) //cout<<b[i]<<" "; cout<<endl;
    for (int i=0; i<=f; i++) v[i] = 0;
    for (int i=n-1; i>=0; i--) {
        tot += ask(a[i]-1);
        b[i] += ask(a[i]-1);
        update(a[i],1);
    }//for (int i=0; i<n; i++) //cout<<b[i]<<" ";cout<<endl;
    for (int i=0; i<=f; i++) v[i] = 0;
    k *= 2LL;
    long long res = 0;
    int last = 0;
    //cout<<tot<<endl;
    for (int i=0; i<n-1; i++) {
        int c = tot;
        long long tmp = 0;
        int in = last+1;
        if (tot<=k) {
            //cout<<i<<" "<<tot<<" "<<last<<" "<<res<<endl;
            if (i<last || last!=n-1) res += n-1-last;
            if (last<=i) last++;
            //continue;
        }
        else {
            for (int j=last+1; j<n-1; j++) {
                vis[j] = 1;
                tot -= 2*b[j];
                tot += 2*query(f,a[j]+1);
                //cout<<2*(b[j])<<" "<<2*(query(f,min(a[j]+1,f)))<<endl;;
                update(a[j],1);
                //cout<<j<<" "<<tot<<endl;
                if (tot<=k) {
                    res += n-1-j;
                    //cout<<i<<" "<<j<<" "<<res<<endl;
                    last = j;
                    break;
                }
            }
        }
        if (i!=n-1 && vis[i+1]) update(a[i+1],-1);
        if (i!=n-1 && vis[i+1]) {
            tot += 2*b[i+1];
            tot -= 2*ask(a[i+1]-1);
        }
        //cout<<tot<<endl;
    }
    cout<<res<<endl;

    return 0;

}
