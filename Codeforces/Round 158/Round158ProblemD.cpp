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

pair<int,int> white[100010];
pair<int,int> black[100010];
priority_queue<pair<int,int> > qw, qb;
int w,b;
int n;
int lastw, lastb;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    for (int i=0; i<n; i++) {
        int c,s;
        scanf("%d%d",&c,&s);
        if (c) white[w++] = make_pair(s,i);
        else black[b++] = make_pair(s,i);
    }
    sort(white,white+w);
    sort(black,black+b);
    reverse(white,white+w);
    reverse(black,black+b);

    int i = 0, j = 0;

    while (true) {
        if (i<w) {
            if (!qb.empty()) {
                pair<int,int> p = qb.top();
                qb.pop();
                if (p.first>white[i].first) {
                    p.first -= white[i].first;
                    qb.push(p);
                    cout<<white[i].second+1<<" "<<p.second+1<<" "<<white[i].first<<endl;
                    i++;
                }
                else {
                    white[i].first -= p.first;
                    qw.push(white[i]);
                    cout<<white[i].second+1<<" "<<p.second+1<<" "<<p.first<<endl;
                    i++;
                }
            }
            else {
                qw.push(white[i]);
                if (lastb!=0) cout<<lastb<<" "<<white[i].second+1<<" "<<0<<endl;
                i++;
            }
            if (lastw==0) lastw = white[i].second+1;
        }
        if (j<b) {
            if (!qw.empty()) {
                pair<int,int> p = qw.top();
                qw.pop();
                if (p.first>black[j].first) {
                    p.first -= black[j].first;
                    qw.push(p);
                    cout<<black[j].second+1<<" "<<p.second+1<<" "<<black[j].first<<endl;
                    j++;
                }
                else {
                    black[j].first -= p.first;
                    qb.push(black[j]);
                    cout<<black[j].second+1<<" "<<p.second+1<<" "<<p.first<<endl;
                    j++;
                }
            }
            else {
                qb.push(black[j]);
                if (lastw!=0) cout<<lastw<<" "<<black[i].second+1<<" "<<0<<endl;
                j++;
            }
            if (lastb==0) lastb = black[j].second+1;
        }
        if (j==b&&i==w) break;
    }

    return 0;

}
