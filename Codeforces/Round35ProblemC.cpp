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

int n,m;
int k;
pair<int,int> beg[11];

int main() {

	freopen("input.txt","r",stdin);
   	freopen("output.txt","w",stdout);

    cin>>n>>m;
    cin>>k;
    for (int i=0; i<k; i++) {
        int a,b;
        cin>>a>>b;
        beg[i] = make_pair(a,b);
    }

    int best = -1;
    pair<int,int> tree;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        int tmp = 10000000;
        for (int kk=0; kk<k; kk++) {
            tmp = min(tmp,abs(beg[kk].first-i)+abs(beg[kk].second-j));
        }
        if (tmp>best)
        {
            best = tmp;
            tree = make_pair(i,j);
        }
    }

    cout<<tree.first<<" "<<tree.second<<endl;

	return 0;

}
