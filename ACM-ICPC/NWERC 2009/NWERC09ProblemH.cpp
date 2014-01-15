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

int a[1000][1000];
int v[10010];
int t;
int n1,n2,n3,n4,n5;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;

    int m = 500;
    int c = 0;
    a[m][m] = 1;
    int k = 1;
    for (int i=0; i<1000; i++) for (int j=0; j<1000; j++) a[i][j] = -1;
    for (int i=0; i<1000; i++) for (int j=0; j<1000; j++) if ((abs(m-i)+abs(m-j))%2!=0) a[i][j] = 0;

    n1 = 1;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    n5 = 0;

    int x = m;
    int y = m;

    while (c<=10000) {

        x++; y++;

        for (int i=x; i>=m-)

        c += k*6;
        k++;
    }


    return 0;

}
