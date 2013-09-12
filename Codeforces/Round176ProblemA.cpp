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

int n;
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int f = n;
    int k = 1;
    int j = 0;
    for (;f>0;) {
        if (f==2 || f==3) {
            cout<<-1; return 0;
        }
        if (f==1) {
            a[j] = k;
            break;
        }
        a[j] = k+1;
        a[j+1] = n-k+1;
        a[n-j-1] = n-k;
        a[n-j-2] = k;
        f -= 4;
        k += 2;
        j += 2;
    }
    for (int i=0; i<n; i++) printf("%d ",a[i]);

    return 0;

}
