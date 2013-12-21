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
string good;
int k;
vector<string> v;
int start[1510];
int last[1510];

int solve(string str, int t) {
    int sum = 0;
    int cnt = 0;
    for (int i=0; i<str.length(); i++) {
        if (good[str[i]-'a']=='0') cnt++;
        if (i>=t && cnt<=k) sum++;
        if (cnt>k) break;
    }
    return sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s>>good>>k;
    for (int i=0; i<s.length(); i++) {
        v.push_back(s.substr(i,s.length()-i));
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i=0; i<v.size(); i++) {
        ans += solve(v[i],start[i]);
        for (int j=i+1; j<v.size(); j++) {
            if (start[j]>0) {
                bool change = 0;
                while (last[i]==last[j] && start[j]<v[j].length() && start[j]<v[i].length()) {
                    if (v[i][start[j]]==v[j][start[j]]) {
                        change = 1;
                        start[j]++;
                    }
                    else break;
                }
                if (change) last[j] = last[i];
            }
            else {
                bool change = 0;
                if (start[j]<v[i].length()) {
                    if (v[i][start[j]]==v[j][start[j]]) {
                        change = 1;
                        start[j]++;
                    }
                }
                while (last[i]==last[j] && start[j]<v[j].length() && start[j]<v[i].length()) {
                    if (v[i][start[j]]==v[j][start[j]]) {
                        start[j]++;
                        change = 1;
                    }
                    else break;
                }
                if (change) last[j] = last[i];
            }
        }
    }
    cout<<ans;

    return 0;

}
