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

string s;
string rev;

struct node{
    char c;
    map<char, int> next;
    vector<int> index;
    node(char _c, int i) {c = _c; index.push_back(i);}
    node() {}
};
vector<node> all;
int m;
int n;
int best;
int res;
int last;

void insert(int cur, int i) {
    if (i==n) return;
    if (all[cur].next.find(rev[i])==all[cur].next.end()) {
        node nd(rev[i], i);
        all[cur].next[rev[i]] = all.size();
        all.push_back(nd);
    }
    else all[all[cur].next[rev[i]]].index.push_back(i);
    insert(all[cur].next[rev[i]], i+1);
}

void search(int cur, int i, int left, int start, int len) {
    if (len>best && len>res) {
        for (int j=0; j<all[cur].index.size(); j++) {
            if (n-all[cur].index[j]+len<=i || n-all[cur].index[j]>=i+len) {
                res = len;
                last = all[cur].index[j];
            }
        }
    }
    if (i==n) return;
    if (start) {
        if (all[cur].next.find(s[i])==all[cur].next.end()) return;
        search(all[cur].next[s[i]], i+1, left, 0, len+1);
    }
    else {
        if (all[cur].next.find(s[i])==all[cur].next.end()) {
            if (left>0) {
                rep(it, all[cur].next) {
                    search((*it).second, i, left-1, 0, len);
                }
            }
        }
        else search(all[cur].next[s[i]], i+1, left, 0, len+1);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    //cin>>s;
    for (int i=0; i<10000; i++) s += 'A';
    for (int j=0; j<10000; j++) s += 'N';
    rev = s;
    reverse(rev.begin(),rev.end());
    for (int i=0; i<rev.length(); i++) {
        if (rev[i]>='N') rev[i] = char('A' + rev[i]-'N');
        else rev[i] = char('N' + rev[i]-'A');
    }
    node root('#', -1);
    all.push_back(root);

    n = s.length();
    for (int i=0; i<rev.length(); i++) {
        insert(0, i);
    }

    best = -1;
    int p;
    int q;
    for (int i=0; i<n; i++) {
        res = 0;
        search(0, i, 2, 1, 0);
        if (res>best && res!=0) {
            best = res;
            p = i;
            q = last;
        }
    }

    if (best<=0) printf("-\n");
    else {
        cout<<s.substr(p, best)<<"\n";
        printf("%d\n%d\n", p+1, n-q);
    }

    return 0;

}
