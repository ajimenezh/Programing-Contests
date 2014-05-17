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

string a,b;
int cnt[28];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b;
    for (int i=0; i<a.length(); i++) cnt[a[i]-'a']++;
    for (int i=0; i<b.length(); i++) cnt[b[i]-'a']--;
    int tot = 0;
    for (int i=0; i<26; i++) tot += abs(cnt[i]);
    cout<<tot<<endl;

    return 0;

}
