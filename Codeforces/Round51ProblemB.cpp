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
int p[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>p[i];
    int l = -1;
    int r = n;

    for (int i=0; i<n; i++) {
        if (i==0) {
            if (p[i]!=1) {
                l = 0;
                break;
            }
        }
        else if (abs(p[i]-p[i-1])>1) {
            l = i;
            break;
        }
    }
    if (l==-1) cout<<0<<" "<<0<<endl;
    else {
        r = n-1;
        for (int i=l+1; i<n; i++) {
            if (abs(p[i]-p[i-1])>1) {
                r = i-1;
                break;
            }
        }

        reverse(p+l,p+r+1);

        for (int i=1; i<n; i++) {
            if (p[i]-p[i-1]!=1) {
                cout<<0<<" "<<0<<endl;
                return 0;
            }
        }
        cout<<l+1<<" "<<r+1<<endl;
    }

    return 0;

}
