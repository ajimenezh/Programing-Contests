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

int k,s;
int ans;
int c[51][51];

int gcd(int a, int b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

void rec(int t, int g, int f) {
    if (ans>=10000) return;
    if (t==k) {
        ans++;
        return;
    }
    for (int i=f; i<=s; i++) {
        if (g==-1) {
            rec(t+1,i,i+1);
        }
        else {
            if (gcd(g,i)!=1) {
                rec(t+1,gcd(g,i),i+1);
            }
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin>>k>>s;
    if (2*k>s) {
        cout<<0<<endl;
        return 0;
    }
    if (4*k>s) {
        for (int i=0; i<=50; i++) {
            c[i][0] = c[i][i] = 1;
            for (int j=1; j<i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
        }

        long long ans = 0;
        for (int i=2; i<=s; i++) {
            int t = s/i;
            ans += c[t][k];
        }
        if (ans>10000) cout<<10000<<endl;
        else cout<<ans<<endl;

        return 0;
    }
    rec(0,-1,2);
    cout<<ans<<endl;

    return 0;

}

