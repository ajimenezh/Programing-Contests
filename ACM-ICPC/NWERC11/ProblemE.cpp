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

int sum[260];
int last[260];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        cout<<s<<endl;

        for (int i=0; i<n; i++) {
            sum[s[i]] = 0;
            last[s[i]] = 0;
        }

        for (int i=0; i<n; i++) {
            last[s[i]] = i;
            sum[s[i]]++;
        }

        long long res = 0;

        for (int i=0; i<n; i++) {
            sum[s[i]]--;
            res += last[s[i]] - i - sum[s[i]];
        }

        printf("%I64d\n",res*5LL);
    }

    return 0;

}
