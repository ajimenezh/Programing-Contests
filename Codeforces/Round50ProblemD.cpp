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

bool dp[110][110];
bool vis[110][110];
int n,k;
string s;
string pos;
set<int> p;
char str[205];
int last[101];

bool solve(int a, int b) {
    //cout<<a<<" "<<b<<endl;
    if (b==s.length() && p.find(a)==p.end()) return false;
    if (b==s.length() && p.find(a)!=p.end()) {
         string s2 = s;
        for (int j=1; j<=s2.length(); j++) {
            bool done = 1;
            for(int t=j; t<s2.length(); t++) {
                if (s2[t]!=s[t-j]) {
                    done = 0; break;
                }
            }
            if (done) {
                b = s.length()-j;
                break;
            }
        }
    }
    if (a==n) return true;
    if (vis[a][b]) return dp[a][b];

    if (str[a]=='?') {
        for (int i=0; i<k; i++) {
            //if (b==s.size()-1 && k==(s[s.size()-1]-'a')) continue;
            bool good = 0;
            string s2 = s.substr(0,b); //cout<<b<<" "<<s2<<endl;
            s2 += char('a'+i);
            for (int j=0; j<=s2.length(); j++) {
                bool done = 1;
                for(int t=j; t<s2.length(); t++) {
                    if (s2[t]!=s[t-j]) {
                        done = 0; break;
                    }
                }//cout<<s2<<" "<<j<<endl;
                if (done) {
                    good = solve(a+1,s2.length()-j);
                    break;
                }
            }

            if (good) {
                str[a] = char('a'+i);
                return true;
            }
        }
    }
    else {
        if (s[b]==str[a]) return solve(a+1,b+1);
        else return solve(a+1,1);
    }

    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    cin>>s;
    cin>>pos;
    for (int i=0; i<n; i++) str[i] = '?';
    for (int i=0; i<pos.length(); i++) {
        if (pos[i]=='1') p.insert(i+s.length());
    }
    for (int i=0; i<pos.length(); i++) {
        if (pos[i]=='1') {
            for (int j=0; j<s.length(); j++) {
                if (str[i+j]=='?') str[i+j] = s[j];
                else{
                    if (str[i+j]!=s[j]) {
                        cout<<"No solution"<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    if (solve(0,0)) {
        for (int j=0; j<n; j++) cout<<str[j];
    }
    else {
        cout<<"No solution"<<endl;
    }

    return 0;

}
