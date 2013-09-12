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
deque<int> q;
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int j = 0; j<n; j++) q.push_back(j+1);

    for (int i=2; i<=n; i++) {
        int f = ((n-1)/i)*i;
        q.push_back(q[f]);
        while (f-i>=0) {
            q[f] = q[f-i];
            f -= i;
        }
        q.pop_front();
        //for (int j=0; j<n; j++) cout<<q[j]<<" "; cout<<endl;
    }

    for (int i=0; i<n; i++) printf("%d ",q[i]);

    return 0;

}
