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

priority_queue<pair<int,int> > pq;
int a[100010];
int type[100010];
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    for (int i=0; i<n; i++) {
        if (a[i]==0) {
            if (!pq.empty()) {
                int l = pq.top().second;
                type[l] = 1;
                pq.pop();
            }
            if (!pq.empty()) {
                int l = pq.top().second;
                type[l] = 2;
                pq.pop();
            }
            if (!pq.empty()) {
                int l = pq.top().second;
                type[l] = 3;
                pq.pop();
            }
        }
        else {
            pq.push(make_pair(a[i],i));
        }
    }
    int x = 0, y = 0, z = 0;
    for (int i=0; i<n; i++) {
        if (a[i]==0) {
            vector<string> vs;
            if (x>0) {
                x--;
                vs.push_back("popStack");
            }
            if (y>0) {
                y--;
                vs.push_back("popQueue");
            }
            if (z>0) {
                z--;
                vs.push_back("popFront");
            }
            cout<<vs.size();
            for (int j=0; j<vs.size(); j++) {
                cout<<" "<<vs[j];
            }
            cout<<"\n";
        }
        else {
            if (type[i]==1) {
                x++;
                cout<<"pushStack\n";
            }
            else if (type[i]==2) {
                y++;
                cout<<"pushQueue\n";
            }
            else if (type[i]==3) {
                z++;
                cout<<"pushFront\n";
            }
            else {
                cout<<"pushBack\n";
            }
        }
    }

    return 0;

}
