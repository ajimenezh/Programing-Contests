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

int d[1000010];
int a = 103993;
const int b = 33102;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<1000005; i++) {
        d[i] = (a / b)%10;
        a = a - d[i]*b;
        a *= 10;
    }
    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {
        int k;
        scanf("%d",&k);
        printf("%d",d[0]);
        if (k>0) printf(".");
        for (int i=0; i<k; i++) {
            printf("%d",d[i+1]);
        }
        printf("\n");
    }

    return 0;

}
