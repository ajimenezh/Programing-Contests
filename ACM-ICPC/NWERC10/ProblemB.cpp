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

int n;
pair<int,int> a[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n;
        string s;
        cin>>s;
        for (int i=0; i<n; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i] = make_pair(-x,y);
        }
        sort(a,a+n);
        priority_queue<pair<int,int> > q;
        int p = 0, j = 0;
        int start = 0;
        if (s[0]=='P') {
            start = 1;
            p += a[0].first;
        }
        for (int i=start; i<n; i+=2) {
            q.push(make_pair(-a[i].second,-a[i].first));
            if (i+1<n) {
                q.push(make_pair(-a[i+1].second,-a[i+1].first));
                p -= q.top().second;
                q.pop();
            }
        }
        while (!q.empty()) {
            j += q.top().first;
            q.pop();
        }

        cout<<-p<<" "<<-j<<endl;
    }

    return 0;

}
