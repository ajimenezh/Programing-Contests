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
#include <fstream>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define offset 10000
#define MAXN 100000

pair<pair<int,int>, int> tran[35][6];
int ind(char c) {
    if (c=='-') return 0;
    else if (c=='1') return 1;
    else if (c=='0') return 2;
    else if (c=='$') return 3;
    else if (c=='#') return 4;
    else if (c=='%') return 5;
    else if (c=='L') return -1;
    else if (c=='R') return 1;
    else return 0;
}
char letter[] = {'-','1','0','$','#','%'};
int v[MAXN];

int _hash(int k) {
    int h = 0;
    int t = 1;
    for (int i=k-3; i<=k+3; i++) {
        if (v[i]==5) return -1;
        h += v[i]*t;
        t *= 5;
    }
    return h;
}

int break_hash(int h,int k) {
    int t = 5;
    for (int i=k-3; i<=k+3; i++) {
        v[i] = h%t;
        h /= t;
    }
    return h;
}

pair<int,pair<int,int> > dp[78125][35];

pair<int,int> solve(int state, int h, int k) {
    if (h>=0 && dp[h][state].first>=0) {
        break_hash(dp[h][state].first,k);
        return dp[h][state].second;
    }
    int kk = k;
    int st = state;
    while (state!=-1 && abs(kk-k)<4) {
        int w = v[kk];
        pair<pair<int,int>,int> p = tran[state][w];
        v[kk] = p.first.first;
        state = p.first.second;
        kk += p.second;
    }
    int hh = _hash(k);
    if (h>=0) dp[h][st] = make_pair(hh,make_pair(kk-k,state));
    return make_pair(kk-k,state);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ifstream input;
    input.open("C:\\Users\\Alex\\Documents\\Projects\\Codeforces\\TuringScript.txt");
    ofstream debug;
    debug.open("debug.txt");

    string s;
    input>>s;
    for (int i=1; i<119; i++) {
        input>>s;
        for (int j=0; j<s.length(); j++) {
            if (s[j]==',' || s[j]==':') s[j] = ' ';
        }
        stringstream ss(s);
        ss>>s;
        int st = 0;
        if (s.length()==6) st = s[5]-'0';
        else st = (s[5] - '0')*10 + s[6]-'0';
        ss>>s;int car = ind(s[0]);
        ss>>s; int prin = ind(s[0]);
        ss>>s;int to = ind(s[0]);
        int des = 0;
        ss>>s;
        if (s=="end") des = -1;
        else {
            if (s.length()==6) des = s[5]-'0';
            else des = (s[5] - '0')*10 + s[6]-'0';
        }
        tran[st][car] = make_pair(make_pair(prin,des),to);
    }

    for (int i=0; i<78125; i++) for (int j=0; j<35; j++) dp[i][j].first = -1;

    while (cin>>s) {
        debug<<s<<endl;
        for (int i=0; i<MAXN; i++) v[i] = 0;
        for (int i=1; i<s.length();i++) {
            v[i+offset] = ind(s[i]);
        }
        v[offset] = ind('%');
        int k = offset+1;
        int state = 0;
        while(state!=-1) {
            int h = _hash(k); //cout<<h<<endl;
            pair<int,int> p = solve(state,h, k);
            k += p.first;
            state = p.second;
            if (k>MAXN || k<0) debug<<"ERROR: Fuera de limites\n";

            int i,j;
        for (i=0; i<MAXN; i++) if (v[i]!=0) break;
        for (j=MAXN-1; j>=0; j--) if (v[j]!=0) break;
        for (; i<=j; i++) printf("%c",letter[v[i]]);
        printf("\n");
        cout<<k<<endl;
        }

        int i,j;
        for (i=0; i<MAXN; i++) if (v[i]!=0) break;
        for (j=MAXN-1; j>=0; j--) if (v[j]!=0) break;
        for (; i<=j; i++) printf("%c",letter[v[i]]);
        printf("\n");
    }

    return 0;

}
