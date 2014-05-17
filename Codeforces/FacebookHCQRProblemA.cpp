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
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int a[27];
vector<int> v;
string s;

char lower(char c) {
    if (c>='a' && c<='z') return c;
    return c - 'A' + 'a';
}
bool letter(char c){
    if (c>='a' && c<='z') return true;
    if (c>='A' && c<='Z') return true;
    return false;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    getline(cin,s);

    for (int tt=0; tt<t; tt++) {
        getline(cin,s);
        int n = s.length();
        for (int i=0; i<26; i++) a[i] = 0;
        for (int i=0; i<n; i++) if (letter(s[i])) {
            a[lower(s[i])-'a']++;
        }

        v.clear();

        for (int i=0; i<26; i++) {
            v.push_back(a[i]);
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        int res = 0;
        for (int i=0; i<26; i++) {
            res += (26-i)*v[i];
        }

        printf("Case #%d: %d\n",tt+1,res);
    }

    return 0;

}
