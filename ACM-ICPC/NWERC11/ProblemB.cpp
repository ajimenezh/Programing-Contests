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

int t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        int a,b;
        scanf("%d/%d",&a,&b);
        while (a!=1 || b!=1) {
            if (a>=b) {
                cout<<"R";
                a -= b;
                swap(a,b);
            }
            else {
                cout<<"L";
                swap(a,b);
                a -= b;
            }
        }
        cout<<"\n";
    }

    return 0;

}
