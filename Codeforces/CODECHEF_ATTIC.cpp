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

char buf[1000010];
string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",buf);
        s = buf;
        int n = s.size();

        int ind = 0;
        int m = 0;
        int sol = 0;

        for (int i=0; i<n; i++) if (s[i]=='.') {
            int j = i;
            while (j<n && s[j]=='.') j++;
            if ((j-i)>m) sol++;
            m = max(j-i,m);
            i = j-1;
        }
        printf("%d\n",sol);
    }

    return 0;

}
