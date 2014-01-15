#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

#define MAXN 1000000

int t;
set<int> ei[MAXN];
set<int> eo[MAXN];
map<int,string> mapa;
map<string,int> mapaInv;
int ind;
int q[MAXN];

void add_edge(int a,int b) {
    ei[b].insert(a);
    eo[a].insert(b);
}

vector<int> topsort() {
    vector<int> l;
    int in = 0;
    int fin = 0;
    bool multiple = 0;
    for (int i=0; i<ind; i++) if (ei[i].size()==0) q[fin++] = i;
    while (in!=fin) {
        if (fin-in>1) {
            multiple = 1;
        }
        int i = q[in++];
        l.push_back(i);

        rep(it,eo[i]) {

            ei[*it].erase(i);
            if (ei[*it].size()==0) {
                q[fin++] = *it;
            }
        }
        eo[i].clear();
    }
    for (int i=0; i<ind; i++) if (ei[i].size()!=0) return vector<int> (0,0);
    if (multiple) return vector<int> (1,-1);
    return l;
}


int main() {

    cin>>t;
    string s;
    getline(cin,s);
    for (int tt=0;tt<t;tt++) {
        mapa.clear();
        mapaInv.clear();

        for (int i=0; i<ind; i++) eo[i].clear();
        for (int i=0; i<ind; i++) ei[i].clear();

        bool bad = 0;

        ind = 0;
        getline(cin,s);
        string str;
        int k = 0;

        int last = -1;
        while (k<s.length()) {
            char c = s[k++];
            if (k==1 && c!='.') {
                bad = 1;
                break;
            }
            int f = k;
            while (k<s.length() && s[k]!='.' && s[k]!='<' && s[k]!='>') k++;
            str = s.substr(f,k-f);
            if (mapaInv.find(str)==mapaInv.end()) {
                mapa[ind++] = str;
                mapaInv[str] = ind-1;
            }
            int d = mapaInv[str];
            if (c=='.') {
                if (last!=-1) add_edge(last,d);
                last = d;
            }
            else if (c=='>') {
                add_edge(last,d);
            }
            else {
                add_edge(d,last);
            }

        }


        if (bad) {
            cout<<"invalid"<<endl;
            cout<<"\n";
            continue;
        }

        int c1 = 0, c2 = 0;
        int p;
        for (int i=0; i<ind; i++) {
            if (ei[i].size()==0) c2++;
            if (eo[i].size()==0) {c1++; p = i;}
        }

        if (c1!=1 || c2!=1) {
            cout<<"invalid";
            cout<<"\n";
            continue;
        }

        vector<int> v1 = topsort();

        if (v1.size()==0) {
            cout<<"invalid";
            cout<<"\n";
            continue;
        }

        if (v1.size()==1 && v1[0]==-1) {
            cout<<"valid";
            cout<<"\n";
            continue;
        }


        for (int i=0; i<v1.size(); i++) {
            cout<<mapa[v1[i]];
            if (i!=v1.size()-1) cout<<",";
            else cout<<"\n";
        }

    }

    return 0;

}
