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

int n;
string s;
int last1[27];
int last2[27];
int last3[10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n;
        cin>>s;

        long long tot = 0;

        for (char i='a'; i<='z'; i++) {
            for (int j=0; j<n; j++) if (s[j]==i) last1[i-'a'] = j;
        }
        for (char i='a'; i<='z'; i++) {
            for (int j=0; j<n; j++) if (s[j]==i) tot += 5LL*(long long)(last1[i-'a']-j);
        }
        for (char i='A'; i<='Z'; i++) {
            for (int j=0; j<n; j++) if (s[j]==i) last2[i-'A'] = j;
        }
        for (char i='A'; i<='Z'; i++) {
            for (int j=0; j<n; j++) if (s[j]==i) tot += 5LL*(long long)(last2[i-'A']-j);
        }
        for (char i='0'; i<='9'; i++) {
            for (int j=0; j<n; j++) if (s[j]==i) last3[i-'0'] = j;
        }
        for (char i='0'; i<='9'; i++) {
            for (int j=0; j<n; j++) if (s[j]==i) tot += 5LL*(long long)(last3[i-'0']-j);
        }

        long long tmp = 0;
        for (char i='a'; i<='z'; i++) {
            int cnt = 0;
            for (int j=0; j<n; j++) if (s[j]==i) cnt++;
            if (cnt>0) tmp += 5LL*(long long)(cnt-1)*(long long)cnt/2LL;
        }
        for (char i='A'; i<='Z'; i++) {
            int cnt = 0;
            for (int j=0; j<n; j++) if (s[j]==i) cnt++;
            if (cnt>0) tmp += 5LL*(long long)(cnt-1)*(long long)cnt/2LL;
        }
        for (char i='0'; i<='9'; i++) {
            int cnt = 0;
            for (int j=0; j<n; j++) if (s[j]==i) cnt++;
            if (cnt>0) tmp += 5LL*(long long)(cnt-1)*(long long)cnt/2LL;
        }

        cout<<tot-tmp<<endl;
    }

    return 0;

}
