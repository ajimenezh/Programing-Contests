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

int c, n;
int a[101];
bool vis[101];
int b[101];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>c>>n;

        for (int i=0; i<n; i++) scanf("%d",a+i);

        int sum = 0;

        for (int i=0; i<n; i++) sum += a[i];

        if (sum<c) {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }

        sum = c;

        int rest = n;
        for (int i=0; i<n; i++) vis[i] = 0;
        for (int i=0; i<n; i++) b[i] = 0;
        for (int i=0; i<n; i++) {
            int m = 10000000;
            int p = -1;
            for (int j=0; j<n; j++) {
                if (a[j]<m && !vis[j]) {
                    m = a[j];
                    p = j;
                }
            }
            //cout<<m<<" "<<p<<endl;
            if (sum/rest > m) {
                sum -= m;
                rest--;
                b[p] = a[p];
                vis[p] = 1;
            }
            else {
                break;
            }
        }

        //cout<<sum<<" "<<rest<<endl;

        int m = sum/rest;
        sum -= m*rest;


        for (int j=0; j<n; j++) if (!vis[j]) b[j] = m;

        while (sum!=0) {
            m = 0;
            int p = -1;
            for (int j=0; j<n; j++) {
                if (a[j]>m && !vis[j]) {
                    m = a[j];
                    p = j;
                }
            }
            b[p]++;
            sum--;
            vis[p] = 1;
        }

        for (int i=0; i<n; i++) cout<<b[i]<<" "; cout<<endl;
    }


    return 0;

}
