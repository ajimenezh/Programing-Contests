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

int t;
int n,s;
int a[100010];
set<int> songs;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;

    while (t--) {
        cin>>n>>s;

        for (int i=0; i<s; i++) scanf("%d",a+i);

        songs.clear();
        for (int i=0; i<min(n,s); i++) songs.insert(a[i]);

        int res = 0;
        for (int i=0; i<min(n,s); i++) {
            if (songs.size()==min(n,s)) res++;

            songs.erase(a[i]);
            if (i+n<s) songs.insert(a[i+n]);
        }

        if (s<n) res += n-s;

        cout<<res<<endl;
    }

    return 0;

}
