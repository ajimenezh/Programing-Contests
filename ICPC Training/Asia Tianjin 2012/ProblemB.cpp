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

int calc(int a, int t) {
    int tmp = 0;
    while (a>0) {
        tmp += (a%t)*(a%t);
        a /= t;
    }
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n>>m) {
        long long sum = 0;

        for (int i=1; (long long)i*i<=n; i++) {
            if (n%i==0) sum += calc(i,m) + calc(n/i,m);
            if (i*i==n) sum -= calc(i,m);
        }

        vector<int> v;
        while (sum>0) {
            v.push_back(sum%m);
            sum /= m;
        }
        reverse(v.begin(),v.end());
        for (int i=0; i<v.size(); i++) {
            if (v[i]<10) cout<<v[i];
            else cout<<char('A'+(v[i]-10));
        }
        cout<<endl;
    }

    return 0;

}
