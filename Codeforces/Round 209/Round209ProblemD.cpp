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
int a[300010];
int l[300010], r[300010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    int best = 0;
    int last = 0;
    int siz = 1;
    for (int i=0; i<n; i++) l[i] = i;
    for (int i=0; i<n; i++) r[i] = i;
    for (int i=1; i<n; i++) {
        if (a[last]%a[i]==0 && a[last]!=a[i]) {
            l[last] = i;
            last = i;
            l[i] = i;
        }
        else {
            if (a[i]%a[last]==0) {
                l[last] = i;
            }
            else {
                last = i;
            }
        }
    }
    last = n-1;
    for (int i=n-2; i>=0; i--) {
        if (a[last]%a[i]==0 && a[last]!=a[i]) {
            r[last] = i;
            l[i] = max(l[i],l[last]);
            last = i;
            r[i] = i;
        }
        else {
            if (a[i]%a[last]==0) {
                r[last] = i;
            }
            else {
                last = i;
            }
        }
    }
    last = 0;
    for (int i=1; i<n; i++) {
        if (a[last]%a[i]==0 && a[last]!=a[i]) {
            r[i] = min(r[i], r[last]);
            last = i;
        }
        else {
            if (a[i]%a[last]==0) {

            }
            else {
                last = i;
            }
        }
    }

    for (int i=0; i<n; i++) {
        best = max(best, -r[i]+l[i]);
    }

    vector<int> v;
    set<int> all;
    for (int i=0; i<n; i++) {
        if (l[i]-r[i]==best && all.find(r[i])==all.end()) {
            v.push_back(r[i]);
            all.insert(r[i]);
        }
        //cout<<i+1<<" "<<l[i]<<" "<<r[i]<<endl;
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<" "<<best<<endl;
    for (int i=0; i<v.size(); i++) cout<<v[i]+1<<" "; cout<<endl;

    return 0;

}
