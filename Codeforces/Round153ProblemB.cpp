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
int a[100010];

bool check() {
    int asc = 1;
    for (int i=1; i<n; i++) if (a[i]<a[i-1]) {
        asc = 0;
        break;
    }
    int desc = 1;
    for (int i=1; i<n; i++) if (a[i]>a[i-1]) {
        desc = 0;
        break;
    }
    return asc || desc;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    if (n<=2) cout<<-1;
    else {
        for (int i=1; i<n; i++) {
            if (a[i]>a[i-1]) {
                swap(a[i],a[i-1]);
                if (!check()) {
                    cout<<i<<" "<<i+1<<endl;
                    return 0;
                }
                else {
                    swap(a[i],a[i-1]);
                    break;
                }
            }
        }
        for (int i=1; i<n; i++) {
            if (a[i]<a[i-1]) {
                swap(a[i],a[i-1]);
                if (!check()) {
                    cout<<i<<" "<<i+1<<endl;
                    return 0;
                }
                else break;
            }
        }
        cout<<-1;
    }

    return 0;

}
