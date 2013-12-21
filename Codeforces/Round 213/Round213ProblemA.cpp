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

int a;
int v[4100];
string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a;
    cin>>s;
    for (int i=0; i<s.length(); i++) v[i] = s[i]-'0';
    int n = s.length();

    if (a!=0) {

        long long ans = 0;

        map<int,int> cnt;

        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum += v[j];
                cnt[sum]++;
            }
        }

        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum += v[j];
                if (sum!=0 && a%sum==0) ans += cnt[a/sum];
            }
        }

        cout<<ans<<endl;
    }
    else {
        long long ans = 0;

        map<int,int> cnt;

        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum += v[j];
                cnt[sum]++;
            }
        }

        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                ans += cnt[0];
                sum += v[j];
                if (sum==0) ans += n*(n+1)/2 - cnt[0];
            }
        }

        cout<<ans<<endl;
    }

    return 0;

}
