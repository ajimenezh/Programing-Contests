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

    cin>>m>>n;
    if (m<n) {
        cout<<-1;
        return 0;
    }
    if (n==3 && m>4) {
        cout<<-1;
        return 0;
    }
    int a = n;
    m -= n;
    if (n%2!=0) a = n-1;
    int k = 1000000;
    cout<<-k<<" "<<0<<endl;
    cout<<k<<" "<<0<<endl;
    a -= 2;

    for (int i=0; i<a/2; i++) {
        cout<<k-(i+1)*(i+1)<<" "<<1000*(i+2)<<endl;
        cout<<-k+(i+1)*(i+1)<<" "<<1000*(i+2)<<endl;
        if (m>0) {
            m--;
            cout<<k-(i+1)*(i+1)-1<<" "<<1000*(i+1)<<endl;
        }
        if (m>0) {
            m--;
            cout<<-k+(i+1)*(i+1)+1<<" "<<1000*(i+1)<<endl;
        }
    }
    if (n%2!=0) cout<<0<<" "<<k<<endl;
    int j=1;
    int i = 2;
    if (m>0) {
        cout<<-k+2<<" "<<1<<endl;
        m--;
    }
    if (m>0) {
        cout<<k-2<<" "<<1<<endl;
        m--;
    }
    if (m>0) {
        cout<<0<<" "<<k-1<<endl;
        m--;
    }

    return 0;

}
