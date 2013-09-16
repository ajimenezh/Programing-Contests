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
priority_queue<int> q;
vector<int> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        q.push(-a);
    }
    while (!q.empty()) {
        int a = q.top();
        q.pop();
        if (!q.empty() && q.top()==a) {
            q.pop();
            q.push(a-1);
        }
        else v.push_back(-a);
    }
    int ans = 0;
    for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
    for (int i=1; i<v.size(); i++) ans += v[i]-v[i-1]-1;
    ans += v[0];
    cout<<ans;

    return 0;

}
