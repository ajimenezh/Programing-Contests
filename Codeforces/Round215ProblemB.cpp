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

int n,m,p;
int a[200010];
int b[200010];
int v[400010];
map<int,int> id;
int cnt[400010];
set<int> in;
set<int> out;
vector<int> ans;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>p;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int j=0; j<m; j++) scanf("%d", b+j);
    for (int i=0; i<n; i++) v[i] = a[i];
    for (int j=n; j<(n+m); j++) v[j] = b[j-n];
    sort(v,v+n+m);
    int k = 0;
    for (int i=0; i<n+m; i++) {
        if (i==0 || v[i]!=v[i-1]) id[v[i]] = k++;
    }
    for (int i=0; i<n; i++) a[i] = id[a[i]];
    for (int i=0; i<m; i++) b[i] = id[b[i]];

    for (int j=0; j<m; j++) {
        cnt[b[j]]++;
        in.insert(b[j]);
    }

    for (int i=0; i<p; i++) {
        if (i+p*(m-1)>=n) break;
        int j;
        for (j=i; j<n; j+=p) {
            cnt[a[j]]--;
            if (cnt[a[j]]==0) {
                in.erase(a[j]);
            }
            if (cnt[a[j]]<0) {
                out.insert(a[j]);
            }
            if ((j-i)/p+1>m) {
                int k = i+((j-i)/p-m)*p;
                cnt[a[k]]++;
                if (cnt[a[k]]==0) {
                    out.erase(a[k]);
                }
                if (cnt[a[k]]>0) {
                    in.insert(a[k]);
                }
            }
            if ((j-i)/p+1>=m) {
                if (in.size()==0 && out.size()==0)
                    ans.push_back(i+((j-i)/p+1-m)*p);
            }
        }
        while (true) {
            int k = i+((j-i)/p-m)*p;
            if (k>=n) break;
            cnt[a[k]]++;
            if (cnt[a[k]]==0) {
                out.erase(a[k]);
            }
            if (cnt[a[k]]>0) {
                in.insert(a[k]);
            }
            j += p;
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i=0; i<ans.size(); i++) cout<<ans[i]+1<<" ";

    return 0;

}
