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

int n,m;
set<int> all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        all.insert(a);
    }
    int res = 0;
    while (all.size()>0) {
        int k = 1;
        int tmp = (*all.begin());
        while (tmp<=1000000000/m && m!=1) {
            tmp *= m;
            if (all.find(tmp)!=all.end()) {
                k++;
                all.erase(tmp);
            }
            else break;
        }
        all.erase(all.begin());
        res += (k+1)/2;
    }

    cout<<res<<endl;

    return 0;

}
