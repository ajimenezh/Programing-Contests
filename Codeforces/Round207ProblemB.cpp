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

long long n,m;
string s, t;
int cnt[26][1000010];

long long gcd(long long a, long long b) {
    if (b>a) return gcd(b,a);
    if (b==0) return  a;
    return gcd(b,a%b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    cin>>s>>t;

    long long g = gcd(n,m);

    long long res = 0;
    if ((n/g!=1 && m/g!=1)) {
        n /= g;
        m /= g;
        for (int i=0; i<s.length(); i++) cnt[s[i]-'a'][i%n]++;
        long long sum = 0;
        for (int i=0; i<t.length(); i++) sum += cnt[t[i]-'a'][i%n];
        sum *= g;
        res = (long long)s.length()*n*g - sum;
    }
    else {
        long long sum = 0;
        int tmp = max(s.length(), t.length());
        for (int i=0, j=0; ;) {
            if (s[i]!=t[j]) sum++;
            if (s.length()>=t.length() && i+1==tmp) break;
            if (t.length()>=s.length() && j+1==tmp) break;
            i = (i+1)%(int)s.length();
            j = (j+1)%(int)t.length();
        }
        res = sum*g;
    }

    cout<<res<<endl;

    return 0;

}
