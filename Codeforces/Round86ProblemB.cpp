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

#define pa 229
#define pb 7919

string s;
string si;
string sf;

vector<int> goodin;
vector<int> goodfn;
int n;
set<int> all;

map<string,int> ma;


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s>>si>>sf;

    n = s.length();

    if (si.length()>n || sf.length()>n) {
        cout<<0;
        return 0;
    }

    for (int i=0; i<n; i++) {
        int tmp = 0;
        for (int j=i; j<n; j++) {
            tmp += s[i]*pb;
            tmp %= pa;
            f[i][j] = tmp;
        }
    }

    for (int i=0; i<n-si.length()+1; i++) {
        bool good = true;
        for (int j=0; j<si.length();j++) {
            if (si[j]!=s[i+j]) {
                good = false;
                break;
            }
        }
        if (good) goodin.push_back(i);
    }

    for (int i=sf.length()-1; i<n; i++) {
        bool good = true;
        for (int j=0; j<sf.length();j++) {
            if (sf[sf.length()-1-j]!=s[i-j]) {
                good = false;
                break;
            }
        }
        if (good) goodfn.push_back(i);
    }

    for (int i=0; i<goodin.size(); i++) for (int j=0; j<goodfn.size(); j++) {
        int a = goodin[i];
        int b = goodfn[j];
        if (b>=a && b-a>=max(si.length(),sf.length())-1) {
            all.insert(f[a][b]);
            //cout<<s.substr(a,b-a+1)<<endl;
        }
    }

    cout<<all.size();

    return 0;

}
