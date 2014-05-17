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

string s;
int n;
string str;
int a[28];

bool check(int k) {
    for (int i=0; i<26; i++) a[i]=0;
    for (int i=0; i<s.length(); i++) a[s[i]-'a']++;
    int t = 0;
    int tot = 0;
    for (int i=0; i<26; i++) {
        if (a[i]) {
            tot += (a[i]-1)/k+1;
        }
    }
    if (tot>n) return false;
    str = "";
    for (int i=0; i<26; i++) {
        if (a[i]) {
            tot = (a[i]-1)/k+1;
            for (int j=0; j<tot; j++) str += char(i+'a');
        }
    }
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s>>n;
    set<char> all;
    for (int i=0; i<s.length(); i++) {
        all.insert(s[i]);
    }
    if (all.size()>n) {
        cout<<-1;
        return 0;
    }
    if (n==s.length()) {
        cout<<1<<"\n"<<s<<endl;
    }
    else if (n>s.length()) {
        cout<<1<<endl;
        cout<<s;
        for (int i=0; i<n-s.length(); i++) cout<<"a";
    }
    else {
        int lo = 1;
        int hi = s.length();
        while (lo<hi) {
            int mi = (lo+hi)>>1;
            if (check(mi)) hi = mi;
            else lo = mi+1;
        }
        check(lo);
        cout<<lo<<endl;
        while (str.length()<n) str += 'a';
        cout<<str<<endl;
    }


    return 0;

}
