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
int last;
int c;
int q;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    last = 0;
    q = 0;
    c = 0;
    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a>last+c) {
            c = 0;
            last = a;
            c = b;
            q = max(q,b);
        }
        else {
            c = c - (a-last) + b;
            last = a;
            q = max(q,c);
        }
    }

    cout<<c+last<<" "<<q<<endl;

    return 0;

}
