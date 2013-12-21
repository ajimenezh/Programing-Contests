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

int n,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    if (3*k>n) cout<<-1;
    else {
        for (int i=0; i<k; i++) cout<<i+1<<" ";
        int j = 1;
        for (int i=k; i<3*k; i+=2) {
            cout<<j<<" "<<j<<" ";
            j++;
        }
        for (int i=3*k; i<n; i++) cout<<"1 ";
    }

    return 0;

}
