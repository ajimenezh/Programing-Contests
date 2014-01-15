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
int p[505];
int h[505];
int m;
int pr[550];
int l[550];
int w[550];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        p[i] = 2*(a+b);
        cin>>h[i];
    }
    cin>>m;
    for (int i=0; i<m; i++) {
        cin>>w[i]>>l[i]>>pr[i];
    }

    int c = 0;
    for (int i=0; i<n; i++) {
        int tmp = 100000000;
        for (int j=0; j<m; j++) {
            int k = w[j]/h[i];
            if (k==0) {
                k = (h[i]-1)/w[i]+1;
                //tmp = min(tmp, k*pr[j]*(int)((p[i]-1)/l[j]+1));
            }
            else {
                tmp = min(tmp, pr[j]*(int)(((p[i]-1)/l[j]+1-1)/k+1));
                //cout<<pr[j]*(int)(((p[i]-1)/l[j]+1-1)/k+1)<<endl;
            }
            //cout<<j<<" "<<tmp<<endl;
        }
        c += tmp;
    }

    cout<<c<<endl;

    return 0;

}
