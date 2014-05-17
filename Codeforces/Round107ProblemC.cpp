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

#define MAXN 520000

struct node{
    double best, left, right, sum;
    node(){best = 0.0; left = 0.0; right = 0.0; sum = 0.0;};
}tree[MAXN];
int n;

int m,c;
long long dist[MAXN/2];
int p[MAXN/2];
int num[MAXN/2];

void update(int node, int v)
 {
    if (node==0) return;
    if (node>=n)
    {
        int i = node - n;;
        tree[node].sum = 1.0*(1.0*dist[i+1] - 1.0*dist[i])/2.0;
        tree[node].sum -= 1.0*(1.0*p[i]/100.0)*1.0*c;
        tree[node].sum *= 1.0*v;

        double t = max(tree[node].sum,0.0);

        tree[node].left = tree[node].right = tree[node].best = t;

        cout<<node<<" "<<tree[node].sum<<endl;
    }
    else
    {
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;

        tree[node].best = max(tree[2*node].best,tree[2*node+1].best);
        tree[node].best = max(tree[node].best, tree[2*node].right + tree[2*node+1].left);
        tree[node].best = max(tree[node].best, tree[2*node].right + tree[2*node+1].sum);
        tree[node].best = max(tree[node].best, tree[2*node].sum + tree[2*node+1].left);

        tree[node].left = max(tree[2*node].left, tree[2*node].sum+tree[2*node+1].left);

        tree[node].right = max(tree[2*node+1].right, tree[2*node+1].sum+tree[2*node].right);
    }

    update(node/2, 0);

    return;

}


int main() {

    scanf("%d%d%d",&n,&m,&c);
    for (int i=0; i<n; i++) scanf("%I64d",&dist[i]);
    for (int i=0; i<n-1; i++) scanf("%d",&p[i]);

    for (int i=0; i<n; i++) num[i] = 0;
    for (int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        num[a-1]++;
        num[b-1]--;
    }

    for (int i=0; i<n-1; i++) num[i] = i!=0 ? num[i-1]+num[i] : num[i];
    for (int i=0; i<n-1; i++) cout<<num[i]<<" "; cout<<endl;

    int k;
    int N = n;
    for(k=1; 1<<k<n; k++); n = 1<<k;
    for (int i=0; i<N-1; i++) update(n+i,num[i]);
    for (int i=N-1; i<=n; i++) tree[i+n] = node();

    printf("%.10f\n",max(tree[1].best,0.000000001));

	return 0;

}
