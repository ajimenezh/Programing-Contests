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

string s;
int sumx[100010];
int sumy[100010];
int sumz[100010];
int n;
int m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    n = s.length();
    cin>>m;

    for (int i=0; i<n; i++) {
        if (s[i]=='x') {
            sumx[i+1]++;
        }
        if (s[i]=='z') {
            sumz[i+1]++;
        }
        if (s[i]=='y') {
            sumy[i+1]++;
        }
        sumx[i+1] += sumx[i];
        sumz[i+1] += sumz[i];
        sumy[i+1] += sumy[i];
    }

    for (int i=0; i<m; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        int x = sumx[r]-sumx[l-1];
        int y = sumy[r]-sumy[l-1];
        int z = sumz[r]-sumz[l-1];

        bool good = false;
        if (x==y && x==z) good = true;
        if (x==y && abs(z-x)==1) good = true;
        if (x==z && abs(z-y)==1) good = true;
        if (z==y && abs(z-x)==1) good = true;
        if (r-l+1<=2) good = 1;

        if (good) printf("YES\n");
        else printf("NO\n");
    }

    return 0;

}
