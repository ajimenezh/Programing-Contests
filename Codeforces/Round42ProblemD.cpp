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

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    if (n>2 && m%2==0) {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        for (int i=0; i<m/2; i++) {
            for (int j=2; j<=n; j++) {
                cout<<j<<" "<<2*i+1<<endl;
            }
            for (int j=n; j>=2; j--) {
                cout<<j<<" "<<2*i+2<<endl;
            }
        }
        for (int i=m; i>=1; i--) {
            cout<<1<<" "<<i<<endl;
        }
    }
    else if (m>2 && n%2==0) {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        for (int i=0; i<n/2; i++) {
            for (int j=2; j<=m; j++) {
                cout<<2*i+1<<" "<<j<<endl;
            }
            for (int j=m; j>=2; j--) {
                cout<<2*i+2<<" "<<j<<endl;
            }
        }
        for (int i=n; i>=1; i--) {
            cout<<i<<" "<<1<<endl;
        }
    }
    else if (n>2 && m%2!=0) {
        cout<<1<<endl;
        cout<<n<<" "<<m<<" "<<1<<" "<<m<<endl;
        cout<<1<<" "<<1<<endl;
        for (int i=0; i<m/2 + 1; i++) {
            for (int j=2; j<=n; j++) {
                cout<<j<<" "<<2*i+1<<endl;
            }
            if (i==m/2) continue;
            for (int j=n; j>=2; j--) {
                cout<<j<<" "<<2*i+2<<endl;
            }
        }
        for (int i=m; i>=1; i--) {
            cout<<1<<" "<<i<<endl;
        }
    }
    else if (n==1 && m>1) {
        for (int i=1; i<m; i++) cout<<1<<" "<<i<<endl;
        for (int i=m; i>=1; i--) cout<<1<<" "<<i<<endl;
    }
    else if (n<=2) {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        if (n>1) {for (int i=1; i<=m; i++) cout<<2<<" "<<i<<endl;}
        if (n>1) {for (int i=m; i>=1; i--) cout<<1<<" "<<i<<endl;}
    }

    return 0;

}
