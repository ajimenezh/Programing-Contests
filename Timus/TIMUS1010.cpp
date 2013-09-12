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

int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long now = -1;

    cin>>n;
    long long pre;
    cin>>pre;
    int ans = 0;
    for (int i=1; i<n; i++) {
        long long a;
        cin>>a;
        if (abs((long long)a-(long long)pre)>now) {
            now = abs((long long)a-(long long)pre);
            ans = i-1;
        }
        pre = a;
    }

    cout<<ans+1<<" "<<ans+2;


    return 0;

}
