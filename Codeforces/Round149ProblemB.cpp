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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

pii v[100010];
int n;

int main() {

    scanf("%d",&n);
    fo(i,n)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a>b)
        {
            int t = a; a = b; b = t;
        }
        v[i] = mp(a,b);
    }

    int l,a,b,ind;
    l = 0;
    a = 100;
    b = 0;

    for (int i=0; i<n; i++) if (v[i].second-v[i].first>=l) {
        if (v[i].second-v[i].first==l && !(v[i].first<a || v[i].second>b)) continue;
        a = v[i].first;
        b = v[i].second;
        ind = i;
        l = v[i].second-v[i].first;
    }

    bool exist = true;
    for (int i=0; i<n; i++) if (v[i].first<a || v[i].second>b)
        exist = false;

    if (!exist) cout<<-1;
    else{
        cout<<ind+1<<endl;
    }

	return 0;

}
