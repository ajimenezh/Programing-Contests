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

vector<int> dp[8200];
int dp1[8200];
vector<char> v;
string vs[13];
bool vis[8200];
int t;
const int h1 = 1443;
const int h2 = 13;
int p[13];

char cards[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

void solve(int st) {
    if (st == (1<<13)-1) return;
    if (vis[st]) return;

    vector<int> tmp(13,0);
    int best = 10000;

    //search single

    for (int i=0; i<13; i++) if (((1<<i)&st) == 0) {
        solve(st | (1<<i));
        int st2 = st | (1<<i);
        int now = 1 + dp1[st2];
        if (now<best) {
            best = now;
            tmp = dp[st2];
            tmp[i] = h1*(i+1);
        }
    }

    //search pair

    for (int i=0; i<12; i++) if (((1<<i)&st) == 0) {
        if (((1<<(i+1))&st) == 0 && v[i]==v[i+1]) {
            int st2 = st | (1<<i);
            st2 |= (1<<(i+1));
            solve(st2);
            int now = 1 + dp1[st2];
            if (now<best) {
                best = now;
                tmp = dp[st2];
                int h = h1*(i+1);
                h = h2*h + h1*(i+2);
                tmp[i] = h;
                tmp[i+1] = h;
            }
        }
    }

    //search triple

    for (int i=0; i<11; i++) if (((1<<i)&st) == 0) {
        if (((1<<(i+1))&st) == 0 && v[i]==v[i+1]) {
            if (((1<<(i+2))&st) == 0 && v[i+2]==v[i+1]) {
                int st2 = st | (1<<i);
                st2 |= (1<<(i+1));
                st2 |= (1<<(i+2));
                solve(st2);
                int now = 1 + dp1[st2];
                if (now<best) {
                    best = now;
                    tmp = dp[st2];
                    int h = h1*(i+1);
                    h = h2*h + h1*(i+2);
                    h = h2*h + h1*(i+3);
                    tmp[i] = h;
                    tmp[i+1] = h;
                    tmp[i+2] = h;
                }
            }
        }
    }

    //four cards

    for (int i=0; i<10; i++) if (((1<<i)&st) == 0) {
        if (((1<<(i+1))&st) == 0 && v[i]==v[i+1]) {
            if (((1<<(i+2))&st) == 0 && v[i+2]==v[i+1]) {
                if (((1<<(i+3))&st) == 0 && v[i+2]==v[i+3]) {
                    int st2 = st | (1<<i);
                    st2 |= (1<<(i+1));
                    st2 |= (1<<(i+2));
                    st2 |= (1<<(i+3));
                    solve(st2);
                    int now = 1 + dp1[st2];
                    if (now<best) {
                        best = now;
                        tmp = dp[st2];
                        int h = h1*(i+1);
                        h = h2*h + h1*(i+2);
                        h = h2*h + h1*(i+3);
                        h = h2*h + h1*(i+4);
                        tmp[i] = h;
                        tmp[i+1] = h;
                        tmp[i+2] = h;
                        tmp[i+3] = h;
                    }
                }
            }
        }
    }

    //full house

    for (int i=0; i<11; i++) if (((1<<i)&st) == 0) {
        if (((1<<(i+1))&st) == 0 && v[i]==v[i+1]) {
            if (((1<<(i+2))&st) == 0 && v[i+2]==v[i+1]) {
                for (int k=0; k<12; k++) if (((1<<k)&st) == 0 && v[k]!=v[i]) {
                    if (((1<<(k+1))&st) == 0 && v[k]==v[k+1]) {
                        int st2 = st | (1<<i);
                        st2 |= (1<<(i+1));
                        st2 |= (1<<(i+2));
                        st2 |= (1<<(k));
                        st2 |= (1<<(k+1));
                        solve(st2);
                        int now = 1 + dp1[st2];
                        if (now<best) {
                            best = now;
                            tmp = dp[st2];
                            int h = h1*(i+1);
                            h = h2*h + h1*(i+2);
                            h = h2*h + h1*(i+3);
                            h = h2*h + h1*(k+1);
                            h = h2*h + h1*(k+2);
                            tmp[i] = h;
                            tmp[i+1] = h;
                            tmp[i+2] = h;
                            tmp[k+1] = h;
                            tmp[k] = h;
                        }
                    }
                }
            }
        }
    }

    //straight

    for (int i=0; i<8; i++) if (((1<<i)&st) == 0) {
        int cur = 0;
        int last = i+1;
        int cnt = 0;
        for (int j=0; j<13; j++) if (cards[j]==v[i]) {
            cur = j;
            break;
        }
        for (int j=i; j<13; j++) if (((1<<j)&st) == 0) {
            if (v[j]==cards[cur]) {
                p[cnt++] = j;
                cur++;
            }
            if (cur==13) break;
        }
        if (cnt>=5) {
            int st2 = st;
            for (int j=0; j<cnt; j++) st2 |= 1<<(p[j]);
            solve(st2);
            int now = 1 + dp1[st2];
            if (now<best) {
                best = now;
                tmp = dp[st2];
                int h = h1*(i+1);
                for (int j=1; j<cnt; j++) {
                    h = h2*h + (p[j]+1)*h1;
                }
                for (int j=0; j<cnt; j++) {
                    tmp[p[j]] = h;
                }
            }
        }
    }

    dp[st] = tmp;
    dp1[st] = best;
    vis[st] = 1;
    return;
}

bool done[13];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt = 0; tt<t; tt++) {
        v.clear();
        vector<char> w;
        for (int i=0; i<13; i++) {
            string s;
            cin>>s;
            vs[i] = s;
            w.push_back(s[0]);
        }
        for (char c = '2'; c<='9'; c++) {
            for (int i=0; i<13; i++) if (w[i]==c) v.push_back(c);
        }
        for (int i=0; i<13; i++) if (w[i]=='T') v.push_back('T');
        for (int i=0; i<13; i++) if (w[i]=='J') v.push_back('J');
        for (int i=0; i<13; i++) if (w[i]=='Q') v.push_back('Q');
        for (int i=0; i<13; i++) if (w[i]=='K') v.push_back('K');
        for (int i=0; i<13; i++) if (w[i]=='A') v.push_back('A');

        //for (int i=0; i<13; i++) cout<<v[i]<<" "; cout<<endl;

        for (int i=0; i<(1<<13); i++) vis[i] = 0;
        for (int i=0; i<(1<<13); i++) dp[i] = vector<int> (13,0);
        for (int i=0; i<(1<<13); i++) dp1[i] = 0;

        solve(0);

        cout<<dp1[0]<<endl;
        for (int i=0; i<13; i++) done[i] = 0;
        for (int i=0; i<13; i++) vis[i] = 0;
        for (int i=0; i<13; i++) if (!done[i]) {
            vector<string> ws;
            for (int j=i; j<13; j++) if (dp[0][j]==dp[0][i]) {
                done[j] = 1;
                for (int k=0; k<13; k++) if (vis[k]==0 && vs[k][0]==v[j]) {
                    ws.push_back(vs[k]);
                    vis[k] = 1;
                    break;
                }
            }
            if (ws.size()==5 && ws[0][0]==ws[1][0] && ws[2][0]!=ws[1][0]) {
                for (int j=2; j<ws.size(); j++) cout<<ws[j]<<" ";
                for (int j=0; j<2; j++) cout<<ws[j]<<" ";
            }
            else {
                for (int j=0; j<ws.size(); j++) cout<<ws[j]<<" ";
            }
            cout<<endl;
        }

    }

    return 0;

}
