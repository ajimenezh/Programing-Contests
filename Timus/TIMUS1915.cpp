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

int v[1000010];
deque<int> q, tmp;
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",&v[i]);
    int m = 0;
    for (int i=0; i<n; i++) if (v[i]==-1) m++;
    int x = 0;
    for (int i=0; i<n; i++) {
        if (v[i]>0) {
            q.push_back(v[i]);
            while (q.size()>m) q.pop_front();
        }
        else if (v[i]<0) {
            printf("%d\n",q.back());
            q.pop_back();
            m--;
        }
        else {
            int t = min(m-q.size(),q.size());
            for (int j=0; j<t; j++) {
                tmp.push_back(q.back());
                q.push_front(q.back());
                q.pop_back();
            }
            for (int j=0; j<t; j++) {
                q.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    }

    return 0;

}
