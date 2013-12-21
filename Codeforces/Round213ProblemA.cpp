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

int a[4000*10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    int m;
    string s;
    cin>>m;
    cin>>s;
    n = s.length();

    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += s[j]-'0';
            a[sum]++;
        }
    }
    long long ans = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += s[j]-'0';
            if (m==0) {
                if (sum==0) ans += n*(n+1)/2;
                else ans += a[0];
            }
            else {
                if (sum !=0 && m%sum==0) {
                    if (m/sum < 40000) ans += a[m/sum];
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;

}
