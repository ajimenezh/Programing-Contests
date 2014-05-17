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

int n,m;
pair<int,int> v1[1001];
pair<int,int> v2[1001];

int main() {

    freopen("cowrace.in","r",stdin);
    freopen("cowrace.out","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v1[i] = make_pair(a,b);
    }
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v2[i] = make_pair(a,b);
    }

    int leader = -1;
    int i = 0, j = 0;
    int p1 = 0, p2 = 0;
    int t = 0;

    while (i<n && j<m) {
        if (v1[i].second<v2[j].second) {
            p1 += v1[i].second*v1[i].first;
            i++;
            p2 += v1[i-1].second*v2[j].first;
            v2[j].second -= v1[i-1].second;
        }
        else {
            p2 += v2[j].second*v2[j].first;
            j++;
            p1 += v2[j-1].second*v1[i].first;
            v1[i].second -= v2[j-1].second;
        }
        if (leader == -1) {
                if (p1>p2) leader = 1;
                else leader = 2;
            }
            else {
                if (leader == 1) {
                    if (p2>p1) {
                        t++;
                        leader = 2;
                    }
                }
                else {
                    if (p1>p2) {
                        t++;
                        leader = 1;
                    }
                }
            }
    }

    cout<<t<<endl;

    return 0;

}
