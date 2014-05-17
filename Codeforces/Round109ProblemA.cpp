#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXN 100010

int dp[MAXN];
map<char,char> ma;
set<char> pos;
string s;

int rec(int i)
{
    if (i==s.length()-2 && pos.find(s[i])!=pos.end()) return 1;
    if (i>=s.length()-2) return 0;

    int sol = 1000000;
    if (pos.find(s[i])!=pos.end() && ma[s[i]]==s[i+1])
    {
        sol = min(1+rec(i+1),1+rec(i+2));
    }
    else sol = rec(i+1);

    return sol;
}

int main() {

    cin>>s;
    int k;
    cin>>k;
    fo(i,k)
    {
        string str;
        cin>>str;
        pos.insert(str[0]);
        pos.insert(str[1]);
        ma[s[0]] = s[1];
        ma[s[1]] = s[0];
    }

    cout<<rec(0);

	return 0;

}
