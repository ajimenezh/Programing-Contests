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
vector<int> e[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int c1=0, c2=0;
    for (int i=0; i<n; i++) {
        if (e[i].size()==n-1) c1++;
        if (e[i].size()==1) c2++;
    }
    if (c1==1 && c2==n-1) {
        cout<<"star topology"<<endl;
        return 0;
    }
    c1 = 0;
    for (int i=0; i<n; i++) {
        if (e[i].size()==2) c1++;
    }
    if (c1==n) {
        cout<<"ring topology"<<endl;
        return 0;
    }
    c1 = 0;
    c2 = 0;
    for (int i=0; i<n; i++) {
        if (e[i].size()==2) c1++;
        if (e[i].size()==1) c2++;
    }
    if (c2==2 && c1==n-2) {
        cout<< "bus topology"<<endl;
        return 0;
    }

    cout<<"unknown topology"<<endl;

    return 0;

}
