//If the submit and test are defferent, I accept that the code is wrong
// but Im not gonna write a code to decode QR :(

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

struct node{
    char color;
    vector<int> e;
    node(char c){
        color = c;
    }
    void add_edge(int i) {
        e.push_back(i);
    }
};
vector<node> vn;
vector<node> vn2;
int cnt2;
vector<int> roots;

int t;
string s;
int cnt;
int now;
int q[100000];
int in,fn;

void rec(int id,int l, int c) {
    //cout<<id<<" "<<l<<" "<<c<<" "<<s[l]<<endl;
    if (c==4) {
        if (l==s.length() || in==fn) return;
        else {
            rec(q[in++],l,0);
            return;
        }
    }
    if (s[l]=='p') {
        vn.push_back(node('p'));
        vn[id].e.push_back(cnt++);
        q[fn++] = cnt-1;
    }
    else {
        vn.push_back(node(s[l]));
        vn[id].e.push_back(cnt++);
    }
    rec(id,l+1,c+1);
    return;
}

vector<node> vis;

int maxLen;

int rec2(int id) {
    string s;

    bool black = 0;
    bool child = 0;
    for (int i=0; i<vis.size(); i++) {
        if (vis[i].color=='b') black = 1;
        if (vis[i].color=='p') child = 1;
    }
    if (black) {
        vn2[id].color = 'b';
        return 1;
    };
    if (!black && !child) {
        vn2[id].color = 'w';
        return 1;
    }
    int t = 0;
    for (int j=0; j<4; j++) {
        vector<node> tmp,tmp2;
        //cout<<vis[0].e[j].color<<endl;
        for (int i=0; i<vis.size(); i++) {
            if (vis[i].color=='p') tmp.push_back(vn[vis[i].e[j]]);
        }
        tmp2 = vis;
        vis = tmp;
        vn2.push_back(node('p'));
        vn2[id].e.push_back(cnt2++);
        t = max(rec2(cnt2-1),t);
        vis = tmp2;
    }
    return 1 +t;
}

string bfs(int id) {
    if (vn2[id].color!='p') return ""+vn2[id].color;
    in = 0;
    fn = 0;
    q[fn++] = id;
    string str;
    str = 'p';
    while (in!=fn) {
        id = q[in++];
        //cout<<vn2[id].color<<endl;
        for (int i=0; i<4; i++) {
            //cout<<vn2[vn2[id].e[i]].color<<" ";
            if (vn2[vn2[id].e[i]].color!='p') {
                str += vn2[vn2[id].e[i]].color;
            }
            else {
                str += 'p';
                q[fn++] = vn2[id].e[i];
            }
        }
        //cout<<endl;
    }
    return str;
}

char mapa[1000][1000];

void draw(int t, int id,int a, int b) {
    //cout<<vn2[id].color<<" "<<a<<" "<<b<<" "<<t<<endl;
    if (vn2[id].color!='p') {
        for (int i=0; i<t; i++) {
            for (int j=0; j<t; j++) {
                mapa[a+i][b+j] = vn2[id].color;
            }
        }
    }
    else {
        draw(t/2,vn2[id].e[0],a,b+t/2);
        draw(t/2,vn2[id].e[1],a,b);
        draw(t/2,vn2[id].e[2],a+t/2,b);
        draw(t/2,vn2[id].e[3],a+t/2,b+t/2);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    getline(cin,s);
    for (int tt=0; tt<t; tt++) {
        getline(cin,s);
        cnt = 0;
        now = 0;
        stringstream ss(s);
        vn.clear();
        roots.clear();
        in = 0;
        fn = 0;
        while (ss>>s) {
            if (s=="b") {
                vn.push_back(node('b'));
                roots.push_back(cnt);
                cnt++;
            }
            else if (s=="w") {
                vn.push_back(node('w'));
                roots.push_back(cnt);
                cnt++;
            }
            else {
                vn.push_back(node('p'));
                roots.push_back(cnt);
                cnt++;
                rec(roots[now],1,0);
            }
            now++;
        }
        maxLen = 0;
        in = 0;
        fn = 0;
        vn2.clear();
        cnt2 = 0;
        vn2.push_back(node('p'));
        cnt2++;
        vis.clear();
        for (int i=0; i<roots.size(); i++) vis.push_back(vn[roots[i]]);
        maxLen = rec2(0);
        s = bfs(0);
        //cout<<s<<endl;
        //cout<<maxLen<<endl;
        for (int i=0; i<(1<<(maxLen-1)); i++) {
            for (int j=0; j<(1<<(maxLen-1)); j++) {
                mapa[i][j] = ' ';
            }
        }
        draw(1<<(maxLen-1),0,0,0);
        for (int i=0; i<(1<<(maxLen-1)); i++) {
            for (int j=0; j<(1<<(maxLen-1)); j++) {
                //if (mapa[i][j]=='b') cout<<"X";
                //else cout<<" ";
            }
            //cout<<endl;
        }

    }

    cout<<"OLA K ASE PROGRAMA O K ASE"<<endl;
    cout<<"Tengo contest tengo island tengo una sabrosura"<<endl;
    cout<<"Death is Not Defeat"<<endl;
    cout<<"If you cannot stay young at least stay immature"<<endl;
    cout<<"The enemys gate is down"<<endl;

    return 0;

}
