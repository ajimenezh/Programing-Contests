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

int k, n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;

    if (n==1) {
        if (k==0) cout<<1<<endl;
        else cout<<-1<<endl;
        return 0;
    }

    int t = k - (n/2-1);

    if (t<=0) {
        cout<<-1;
    }
    else {
        cout<<t<<" "<<2*t<<" ";
        int h = 1;
        for (int i=0; i<n-2; i+=2) {
            if (i+2+1==n) {
                while (h==t || h==2*t) h++;
                cout<<h<<endl;
            }
            else {
                while (h==t || h+1==t || h==2*t || h+1==2*t) h++;
                cout<<h<<" "<<h+1<<" ";
                h += 2;
            }
        }
    }

    return 0;

}
