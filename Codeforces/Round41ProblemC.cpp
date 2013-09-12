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

bool good;
bool check(vector<int>& a) {for (int i=0; i<4; i++) if (a[i]!=1) return 1; return 0;}

map<pair<pair<int,int>,pair<int,int> > ,int > vis;

pair<bool,vector<string> > solve(vector<int> a,int mask) {
    if (!check(a)) return make_pair(1,vector<string> (0,""));
    //for (int i=0; i<4; i++) cout<<a[i]<<" "; cout<<endl;
    for (int i=0; i<4; i++) {
        if (a[i]%2==0) {
            if (a[(i+1)%4]%2==0) {
                string s = "/";
                s += char('0'+i+1);
                a[i]/= 2;
                a[(i+1)%4]/=2;
                pair<bool,vector<string> > tmp = solve(a,mask&(~(1<<i)));
                if (tmp.first) {
                    tmp.second.push_back(s);
                    return tmp;
                }
                a[i]*= 2;
                a[(i+1)%4]*=2;
            }
        }
    }

    for (int i=0; i<4; i++) if ((mask & (1<<i))==0 && (a[i]!=1 || a[(i+1)%4]!=1)) {
        a[i]++;
        a[(i+1)%4]++;
        if (vis[make_pair(make_pair(a[0],a[1]),make_pair(a[2],a[3]))]) break;
        vis[make_pair(make_pair(a[0],a[1]),make_pair(a[2],a[3]))] = 1;
        string s = "+";
        s += char('0'+i+1);
        pair<bool,vector<string> > tmp = solve(a,mask|(1<<i));
        if (tmp.first) {
            tmp.second.push_back(s);
            return tmp;
        }
        a[i]--;
        a[(i+1)%4]--;
    }

    return make_pair(0,vector<string> (0,""));
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector<int> a(4,0);

    cin>>a[0]>>a[1]>>a[2]>>a[3];

    pair<bool, vector<string> > tmp = solve(a,0);

    if (!tmp.first) {cout<<-1; return 0;}
    vector<string> v = tmp.second;
    for (int i=0; i<v.size(); i++) cout<<v[v.size()-1-i]<<"\n";

    return 0;

}
