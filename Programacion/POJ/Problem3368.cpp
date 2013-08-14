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

#define left LEFT
#define right RIGHT

pair<int,int> best[300000];
pair<int,int> left[300000];
pair<int,int> right[300000];
int n,m;
int a[100010];

void build(int id, int l, int r) {
    if (l==r && l<=n) {
        best[id] = mp(a[l],1);
        left[id] = mp(a[l],1);
        right[id] = mp(a[l],1);
        return;
    }
    if (l>=n) {
		best[id] = mp(0,0);
		left[id] = mp(0,0);
        right[id] = mp(0,0);
		return;
	}

    int h = (l+r)/2;
    build(2*id,l,h);
    build(2*id+1,h+1,r);

    if (left[2*id+1].first==right[2*id].first) {
        if (best[id].second<left[2*id+1].second+right[2*id].second) {
            best[id].first = right[2*id].first;
            best[id].second = left[2*id+1].second+right[2*id].second;
        }
    }

    if (best[2*id].second>best[id].second) best[id] = best[2*id];
    if (best[2*id+1].second>best[id].second) best[id] = best[2*id+1];
    
    left[id] = left[2*id];
    right[id] = right[2*id+1];
    if (left[2*id].second==(h-l+1) && left[2*id+1].first==left[2*id].first) 
		left[id].second += left[2*id+1].second;
	
	if (right[2*id+1].second==(r-(h+1)+1) && right[2*id+1].first==right[2*id].first) 
		right[id].second += right[2*id].second;

}

int query(int id, int l, int r, int ll, int rr) {
	if (l>rr || r<ll) return 0;
	if (l>=ll && r<=rr) return best[id].second;
	
	int h = (l+r)>>1;
	int tmp = 0;
	tmp = max(query(2*id,l,h,ll,rr),query(2*id+1,h+1,r,ll,rr));
	
	if (right[2*id].first==left[2*id+1].first) {
		int t = 0;
		if (r>=h) {
			t = min(right[2*id].first,ll-h+1);
		}
		else t = max(0,r - max(h-right[2*id].first+1,ll) + 1);
		tmp = max(tmp,t);
	}
	
	return tmp;
}
	

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    while (cin>>n>>m && n!=0) {

		for (int i=1; i<=n; i++) scanf("%d",a+i);

		build(1,1,n); cout<<n<<" "<<m<<endl;

		for (int i=0; i<m; i++) {
			int a,b;
			scanf("%d%d",&a,&b); 
			printf("%d\n",query(1,1,n,a,b));
		}
	}

    return 0;

}
