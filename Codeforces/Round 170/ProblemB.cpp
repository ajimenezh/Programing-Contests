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

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    if (m==3&&n>=5) {
        cout<<-1<<endl;
    }
    else {
        int r = 9999999;
        double delta = acos(-1.0)*2.0/(double)m;
        for (int i=0; i<m; i++) {
            cout<<(int)(r*cos(i*delta))<<" "<<(int)(r*sin(i*delta))<<endl;
        }
        r = 999999;
        delta = acos(-1.0)*2.0/(double)(m)*0.234 + 0.12;
        for (int i=1; i<=(n-m); i++) {
            cout<<(int)(r*cos(i*delta))<<" "<<(int)(r*sin(i*delta))<<endl;
        }
    }

    return 0;

}
