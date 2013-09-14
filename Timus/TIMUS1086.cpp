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

bool prime[200000];
vector<int> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<200000; i++) prime[i] = 1;
    for (int i=2; i*i<200000; i++) if (prime[i]) {
        for (int j=i*i; j<200000; j+=i) prime[j] = 0;
    }
    for (int j=1; j<200000; j++) if (prime[j]) v.push_back(j);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        cout<<v[n]<<endl;
    }

    return 0;

}
