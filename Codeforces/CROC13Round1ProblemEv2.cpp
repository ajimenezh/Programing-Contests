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

int n,m;
int a[100010];
int b[100010];
int id[320];
int sz;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    sz = sqrt(n) + 1;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) scanf("%d",b+i);
    for (int i=0; i<=sz; i++) id[i] = -1;

    for (int i=0; i<m; i++) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            y--; x--;
            int j = y/sz + 1;
            if (id[j-1]!=-1) {
                for (int p=(j-1)*sz, r=id[j-1]; p<min(sz*j, n) && r<n; p++, r++) {
                    b[p] = a[r];
                }
                id[j-1] = -1;
            }
            for (; y<min(j*sz, n) && x<n && k; k--) {
                b[y++] = a[x++];
            }
            while (k>sz) {
                id[j] = x;
                x += sz;
                k -= sz;
                j++;
                y += sz;
            }
            if (j<=sz && id[j]!=-1) {
                for (int p=(j)*sz, r=id[j]; p<min(sz*(j+1), n) && r<n; p++, r++) {
                    b[p] = a[r];
                }
                id[j] = -1;
            }
            for (int p=y; p<min((j+1)*sz, n) && k; p++, k--) {
                b[p] = a[x++];
            }

            //for (int j=0; j<n; j++) cout<<b[j]<<" "; cout<<endl;
            //cout<<sz<<endl;
            //for (int j=0; j<=sz; j++) cout<<id[j]<<" "; cout<<endl;
        }
        else {
            int y;
            scanf("%d",&y);
            y--;
            int j = y/sz;
            if (id[j]!=-1) {
                for (int p=(j)*sz, r=id[j]; p<min(sz*(j+1), n); p++, r++) {
                    b[p] = a[r];
                }
                id[j] = -1;
            }
            //for (int j=0; j<n; j++) cout<<b[j]<<" "; cout<<endl;
            cout<<b[y]<<"\n";
        }
    }

    return 0;

}
