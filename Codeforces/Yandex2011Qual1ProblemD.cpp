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

int n,m;
int a[40];
pair<int,int> p[40];
int res[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) cin>>a[i];

    int cur = 0;
    for (int i=0; i<n; i++) {
        cur = -1;
        for (int j=0; j<m; j++) {
            if (a[j] && (i==0 || j!=res[i-1]) && (i<n-1 || j!=res[0])) {
                if (i>0) {
                    if (j==res[0] || a[j]>a[cur]) cur = j;
                } else {
                    if (cur==-1 || a[j]<a[cur]) cur = j;
                }
            }
        }
        if (cur==-1) break;
        a[cur]--;
        res[i] = cur;
    }

    if (cur==-1) cout<<-1<<endl;
    else for (int i=0; i<n; i++) cout<<res[i]+1<<" ";

    return 0;

}
