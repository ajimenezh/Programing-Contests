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
string x,y;
int sum[1000010][26];

long long gcd(long long a, long long b){
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>x>>y;

    long long g = gcd(m,n);

    int len = gcd(x.length(), y.length());

    for (int i=0; i<x.length(); i++) sum[i%len][x[i]-'a']++;

    long long res = 0;

    for (int i=0; i<y.length(); i++) res += sum[i%len][y[i]-'a'];

    cout<<n*x.length() - res*g<<endl;

    return 0;

}
