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

map<pair<int,int>,int> index;
map<int,int> cant;

int n,k;
int a[400010];

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

   	cin>>n>>k;
   	for (int i=0; i<n; i++) scanf("%d",&a[i]);

   	for (int i=0; i<n; i++) cant[a[i]] = 0;
   	for (int i=0; i<n; i++) {
        cant[a[i]]++;
        index[make_pair(a[i],cant[a[i]])] = i;
   	}

    for (int i=0; i<n; i++) cant[a[i]] = 0;

    long long res = 0;
    int last = 0;
    for (int i=0; i<n; i++) {
        cant[a[i]]++;
        if (cant[a[i]]>=k) {
            map<pair<int,int>,int>::iterator it1,it2;
            it1 = index.find(make_pair(a[i],cant[a[i]]));
            it2 = index.find(make_pair(a[i],cant[a[i]]-k+1));
            if (last <= (*it2).second)
                res += (long long)(n - (*it1).second)*(long long)((*it2).second - last+1);
            last = max((*it2).second + 1,last);
        }
        //cout<<i<<" "<<res<<" "<<last<<endl;
    }

    cout<<res<<endl;

	return 0;

}
