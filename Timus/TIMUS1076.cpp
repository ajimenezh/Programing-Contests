//* REFERENCE : http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=hungarianAlgorithm *//
//* AUTHOR OF THE ARTICLE : x-ray

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

#define N 155
#define INF 1000000000

int n;
int cost[N][N];
int sum;
int max_match;
int lx[N],ly[N];
int xy[N];
int yx[N];
bool S[N], T[N];
int slack[N];
int slackx[N];
int prev[N];

void init_labels()
{
    for (int i = 0; i <= n; i++) lx[i] = 0;
    for (int i = 0; i <= n; i++) ly[i] = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            lx[x] = max(lx[x], cost[x][y]);
        }
    }
}

void update_labels()
{
    int x, y, delta = INF;
    for (y = 0; y < n; y++)
        if (!T[y])
            delta = min(delta, slack[y]);
    for (x = 0; x < n; x++)
        if (S[x]) lx[x] -= delta;
    for (y = 0; y < n; y++)
        if (T[y]) ly[y] += delta;
    for (y = 0; y < n; y++)
        if (!T[y])
            slack[y] -= delta;
}

void add_to_tree(int x, int prevx)
{
    S[x] = true;
    prev[x] = prevx;
    for (int y = 0; y < n; y++)
        if (lx[x] + ly[y] - cost[x][y] < slack[y])
        {
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackx[y] = x;
        }
}

void augment()
{
    if (max_match == n) return;
    int x, y, root;
    int q[N], wr = 0, rd = 0;

    for (int i=0; i<n; i++) S[i] = false;
    for (int i=0; i<n; i++) T[i] = false;
    for (int i=0; i<n; i++) prev[i] = -1;
    for (x = 0; x < n; x++)
        if (xy[x] == -1)
        {
            q[wr++] = root = x;
            prev[x] = -2;
            S[x] = true;
            break;
        }

    for (y = 0; y < n; y++)
    {
        slack[y] = lx[root] + ly[y] - cost[root][y];
        slackx[y] = root;
    }


    while (true)
    {
        while (rd < wr)
        {
            x = q[rd++];
            for (y = 0; y < n; y++)
                if (cost[x][y] == lx[x] + ly[y] &&  !T[y])
                {
                    if (yx[y] == -1) break;

                    T[y] = true;
                    q[wr++] = yx[y];

                    add_to_tree(yx[y], x);
                }
            if (y < n) break;
        }
        if (y < n) break;

        update_labels();
        wr = rd = 0;
        for (y = 0; y < n; y++)

            if (!T[y] &&  slack[y] == 0)
            {
                if (yx[y] == -1)
                {
                    x = slackx[y];
                    break;
                }
                else
                {
                    T[y] = true;
                    if (!S[yx[y]])
                    {
                        q[wr++] = yx[y];

                        add_to_tree(yx[y], slackx[y]);

                    }
                }
            }
        if (y < n) break;
    }

    if (y < n)
    {
        max_match++;

        for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty)
        {
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        augment();
    }
}

int hungarian()
{
    int ret = 0;
    max_match = 0;
    for (int i=0; i<n; i++) xy[i] = -1;
    for (int i=0; i<n; i++) yx[i] = -1;
    init_labels();
    augment();
    for (int x = 0; x < n; x++)
        ret += cost[x][xy[x]];
    return ret;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d",&cost[i][j]);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) sum += cost[i][j];

    sum -= hungarian();

    cout<<sum;

    return 0;

}
