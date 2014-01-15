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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    map<int,int> prime;

    prime[1] = 1;
    prime[2] = 1;
    prime[3] = 1;
    prime[5] = 1;
    prime[7] = 1;

    for (int i=1; i<12; i++) {
        vector<int> v(i,0);
        int all = 0;
        for (int k=0; k<i; k++) v[k] = k+1;
        do {
            int cnt[12];
            for (int k=0; k<=i; k++) cnt[k] = 0;
            bool good = 1;
            for (int k=0; k<i; k++) {
                int sum = 0;
                for (int j=1; j<v[k]; j++) sum += cnt[j];
                if (!prime[sum+1]) good = 0;
                cnt[v[k]]++;
            }
            if (good) {
                all++;
                //for (int k=0; k<i; k++) cout<<v[k]<<" "; cout<<endl;
            }
        } while (next_permutation(v.begin(),v.end()));
        cout<<i<<" "<<all<<endl;
    }

    int f = 3;
    cout<<"1 1"<<endl;
    long long ans = 2;
    for (int i=2; i<15; i+=2) {
        cout<<i<<" "<<ans<<endl;
        ans *= f;
        cout<<i+1<<" "<<ans<<endl;
        ans *= f;
        f++;
    }

    return 0;

}
