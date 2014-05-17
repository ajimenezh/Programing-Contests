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

int t;
int n;
int a[21],b[21],x[21];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>a[i];
        for (int i=0; i<n; i++) cin>>b[i];

        x[0] = 1;

        for (int i=1; i<n; i++) {
            if (a[i]>a[i-1]) {
                x[i] = x[i]+1;
            }
            else {
                for (int j=0; j<i; j++) {
                    x[j] = x[j]+1;
                }
                x[i] = x[0]-1;
            }
        }

        printf("Case #%d: ",tt+1);
        for (int i=0; i<n; i++) cout<<x[i]<<" ";
        cout<<endl;
    }

    return 0;

}
