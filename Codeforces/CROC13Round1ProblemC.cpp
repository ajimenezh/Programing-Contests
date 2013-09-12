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
set<int> s;
int good[256];
int v[12];
int v2[3];
int in[10];
vector<string> vs;

bool check(int* w, int m) {
    for (int i=0; i<m/2; i++) {
        if (w[i]!=w[m-1-i]) return 0;
    }
    for (int i=0; i<10; i++) in[i] = 0;
    for (int i=0; i<m; i++) in[w[i]]++;
    rep(it,s) if (in[*it]==0) return 0;
    return 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        cin>>a;
        s.insert(a);
    }
    if (n>=7) {
        cout<<0<<endl;
        return 0;
    }
    for (int i=0; i<256; i++) {
        int a = i;
        bool bad = 0;
        if (i==0 && s.find(0)==s.end()) {
            good[0] = 0;
            continue;
        }
        while (a>0) {
            if (s.find(a%10)==s.end()) {
                bad = 1;
                break;
            }
            a /= 10;
        }
        if (!bad) good[i] = 1;
    }
    for (int i=0; i<256; i++) if (good[i]) {
        for (int j=0; j<256; j++) if (good[j]) {
            for (int k=0; k<256; k++) if (good[k]) {
                int c = 0;
                int a = i;
                if (a==0) v[c++] = 0;
                int r = 0;
                while (a>0) {v2[r++]=a%10; a/=10;}
                for (int p=0; p<r; p++) v[c++] = v2[r-1-p];
                a = j;
                if (a==0) v[c++] = 0;
                r = 0;
                while (a>0) {v2[r++]=a%10; a/=10;}
                for (int p=0; p<r; p++) v[c++] = v2[r-1-p];
                a = k;
                if (a==0) v[c++] = 0;
                r = 0;
                while (a>0) {v2[r++]=a%10; a/=10;}
                for (int p=0; p<r; p++) v[c++] = v2[r-1-p];
                v[c] = v[0];
                if (check(v,c+1)) {
                    stringstream ss;
                    ss<<i<<"."<<j<<"."<<k<<"."<<v[0];
                    vs.push_back(ss.str());
                }
                if (c>2 && (v[1]*10+v[0])<256 && (v[1]!=0)) {
                    v[c++] = v[1];
                    v[c] = v[0];
                    if (check(v,c+1)) {
                        stringstream ss;
                        ss<<i<<"."<<j<<"."<<k<<"."<<(v[1]*10+v[0]);
                        vs.push_back(ss.str());
                    }
                    c--;
                }
                if (c>2 && (v[2]*100+v[1]*10+v[0])<256 && v[2]!=0) {
                    v[c++] = v[2];
                    v[c++] = v[1];
                    v[c] = v[0];
                    if (check(v,c+1)) {
                        stringstream ss;
                        ss<<i<<"."<<j<<"."<<k<<"."<<(v[2]*100+v[1]*10+v[0]);
                        vs.push_back(ss.str());
                    }
                }
            }
        }
    }

    cout<<vs.size()<<endl;
    for (int i=0; i<vs.size(); i++) {
        cout<<vs[i]<<"\n";
    }

    return 0;

}
