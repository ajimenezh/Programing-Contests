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
int dp[512][512][9];

bool in(int i, int mask)
{
    return (1<<i) & mask;
}

int generate_mask(int mask1, int mask2)
{
    int low = 0;
    int up = mask1;
    int mid = mask2;
    for (int i=1; i<m-1; i++)
    {
        if (in(i,up) && in(i-1,up) && in(i+1,up) && in(i,mid))
        {
            low |= (1<<i);
        }
    }

    for (int i=1; i<m-1; i++)
    {
        if (in(i,mid) && in(i,up))
        {
            low |= (1<<i); low |= (1<<(i-1)); low |= (1<<(i+1));
        }
    }

    for (int i=1; i<m-1; i++)
    {
        if (in(i,mid) && in(i-1,mid) && in(i+1,mid) && in(i-1,up))
        {
            low |= (1<<(i-1));
        }
    }

    for (int i=1; i<m-1; i++)
    {
        if (in(i,mid) && in(i-1,mid) && in(i+1,mid) && in(i+1,up))
        {
            low |= (1<<(i+1));
        }
    }
    return low;
}

int solve(int mask1, int mask2, int ind)
{
    if (ind == n-1) return 0;
    if (dp[mask1][mask2][ind]!=-1) return dp[mask1][mask2][ind];

    int up = mask1;
    int mid = mask2;
    int mask3 = generate_mask(mask1,mask2);
    int low = mask3;

    int res = solve(mid,mask3,ind+1);

    //Colocamos primer tipo de T
    for (int i=1; i<m-1; i++)
    {
        up = mask1; mid = mask2; low = mask3;
        if (!in(i,up) && !in(i-1,up) && !in(i+1,up) && !in(i,mid) && !in(i,low))
        {
            up |= (1<<i); up |= (1<<(i-1)); up |= (1<<(i+1));
            mid |= (1<<i); low |= (1<<i);
            res = max(res, 1+solve(mid,low,ind+1));
            res = max(res,1+solve(up,mid,ind));
        }
    }

    //Colocamos T al reves
    for (int i=1; i<m-1; i++)
    {
        up = mask1; mid = mask2; low = mask3;
        if (!in(i,low) && !in(i-1,low) && !in(i+1,low) && !in(i,mid) && !in(i,up))
        {
            low |= (1<<i); low |= (1<<(i-1)); low |= (1<<(i+1));
            mid |= (1<<i); up |= (1<<i);
            res = max(res, 1+solve(mid,low,ind+1));
            res = max(res,1+solve(up,mid,ind));
        }
    }

    for (int i=1; i<m-1; i++)
    {
        up = mask1; mid = mask2; low = mask3;
        if (!in(i,mid) && !in(i-1,mid) && !in(i+1,mid) && !in(i-1,up) && !in(i-1,low))
        {
            mid |= (1<<i); mid |= (1<<(i-1)); mid |= (1<<(i+1));
            low |= (1<<(i-1)); up |= (1<<(i-1));
            res = max(res, 1+solve(mid,low,ind+1));
            res = max(res,1+solve(up,mid,ind));
        }
    }

    for (int i=1; i<m-1; i++)
    {
        up = mask1; mid = mask2; low = mask3;
        if (!in(i,mid) && !in(i-1,mid) && !in(i+1,mid) && !in(i+1,up) && !in(i+1,low))
        {
            mid |= (1<<i); mid |= (1<<(i-1)); mid |= (1<<(i+1));
            low |= (1<<(i+1)); up |= (1<<(i+1));
            res = max(res, 1+solve(mid,low,ind+1));
            res = max(res,1+solve(up,mid,ind));
        }
    }

    dp[mask1][mask2][ind] = res;

    return res;
}

int main() {

    cin>>n>>m;

    memset(dp,-1,sizeof(dp));
    int res = solve(0,0,0);

    cout<<res<<endl;

	return 0;

}
