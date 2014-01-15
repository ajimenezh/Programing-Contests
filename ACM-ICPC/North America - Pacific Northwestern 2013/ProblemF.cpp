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

    int n;
    while (scanf("%d",&n) && n!=-1) {
        int sum = 1;
        vector<int> v;
        v.push_back(1);
        for (int i=2; i*i<=n; i++) if (n%i==0) {
            if (i*i==n) {
                sum += i;
                v.push_back(i);
            }
            else {
                sum += i + n/i;
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        if (sum==n) sort(v.begin(),v.end());
        if (sum==n) {
            printf("%d = ",n);
            for (int i=0; i<v.size(); i++) {
                cout<<v[i];
                if (i!=v.size()-1) cout<<" + ";
            }
            cout<<"\n";
        }
        else printf("%d is NOT perfect.\n", n);
    }

    return 0;

}
