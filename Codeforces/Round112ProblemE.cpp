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

int dp[1<<22];
int a[1<<20];
int n;

void insert(int k, int i)
{
    if (dp[k]!=-1) return;

    dp[k] = i;

    for (int j=0; j<22; j++) if (k&(1<<j)) {
        insert(k&((1<<j)^((1<<22)-1)),i);
    }

    return;
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);

    for (int i=0; i<(1<<22); i++) dp[i] = -1;
    for (int i=0; i<n; i++) insert(a[i]^((1<<22)-1),a[i]);

    for (int i=0; i<n; i++)
    {
        printf("%d ",dp[a[i]]);
    }
    cout<<endl;

	return 0;

}
