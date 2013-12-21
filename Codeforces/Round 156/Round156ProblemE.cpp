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

long long a[100];
long long gn

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int k = 2;

    int n;
    cin>>n;
    int ans;
    long long x;
    cin>>x;
    for (int i=0; i<k; i++) {
        if (a[i]<=x && x<a[i+1]) {
            ans = i%3;
            break;
        }
    }

    for (int i=1; i<n; i++) {
        scanf("%I64d",&x);
        for (int i=0; i<k; i++) {
            if (a[i]<=x && a[i+1]>x) {
                ans = (ans^(i%3));
                break;
            }
        }
    }

    if (!ans) cout<<"Rublo"<<endl;
    else cout<<"Furlo"<<endl;

    return 0;

}
