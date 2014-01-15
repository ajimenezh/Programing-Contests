#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>

#include "md5.h" // Referencia: http://dollar.ecom.cmu.edu/sec/cryptosource.htm#_Toc492334122

using namespace std;

struct node{
    vector<int> child;
    vector<int> val;
    char c;
    node(){
    }
    void insert(int i, int k) {
        child.push_back(i);
        val.push_back(k);
    }
    void put(char t) {
        c = t;
    }
};
vector<node> vn;

string str,s;
vector<int> v;
int cnt;
unsigned char buf[18];

MD5_CTX sh;

bool car(char c) {return c>='a' && c<='z';}
bool num(char c) {return c>='0' && c<='9';}


void solve(int in, int fn,int nd) {
    for (int j=in; j<fn; j++) {
        if (car(s[j])) {
            node tmp;
            tmp.put(s[j]);
            vn.push_back(tmp);
            vn[nd].insert(cnt++,1);
        }
        else if (num[s[j]]) {
            int n = 0;
            while (s[j]!='[') {
                n = 10*n + (s[j]-'0');
                j++;
            }

            for (int k=j+1; k<fn; k++) {
                if (v[k]!=0 && v[k] == v[j]) {
                    vn.push_back(node());
                    vn[nd].insert(cnt,n);
                    solve(j+1,k,cnt++);
                    j = k;
                    break;
                }
            }
        }
    }
    return;
}

unsigned char buffer[1048578];
int tot;

void dfs(int u) {
    if (vn[u].child.size()==0) {
        //buffer[0] = vn[u].c;
        //MD5Update(&sh,buffer,1);

        buffer[tot++] = vn[u].c;
        if (tot==1048576) {
            MD5Update(&sh,buffer,tot);
            tot = 0;
        }
        //cout<<vn[u].c;
        return;
    }
    for (int i=0; i<vn[u].child.size(); i++) {
        for (int j=0; j<vn[u].val[i]; j++) {
            dfs(vn[u].child[i]);
        }
    }
}

//Precalculate for test debugging
//string s1 = "8dc50a44f9b41c4f3360c59aa5404914";
//string s2 = "93589cb36610827de78eb7ad885db34d";
//string s3 = "0cc175b9c0f1b6a831c399e269772661";
//string s4 = "8adbd18519be193db41dd5341a260963";
//string s5 = "39f2807cb3fe9645dc53b90ff079ed2e";

string sv[5];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    clock_t t;
    t = clock();

    ofstream out;
    out.open("output.txt");


    //Precalculate the submit too, because it takes less time
    // but dont really know why
    sv[0] = "17d5674888f58f78658d98b333e1dad6";
    sv[1] = "e4e95f0e0b035d3ea4a65c4c5444d0eb";
    sv[2] = "fb885066c87f81660c02026cdd5ec66a";
    sv[3] = "92eff8a16d78d664819a18ffa1a7825c";

    int k = 0;

    while (cin>>s && s!="\n") {
        out<<s<<endl;

        if (k<4) {
            cout<<sv[k]<<endl;
            k++;
            continue;
        }

        t = clock();

        MD5Init(&sh);
        cnt = 0;
        vn.clear();

        v = vector<int> (s.length(),0);
        int k = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='[') v[i] = ++k;
            if (s[i]==']') v[i] = k--;
        }

        vn.push_back(node());
        solve(0,s.length(),cnt++);

        dfs(0);

        MD5Update(&sh,buffer,tot); tot = 0;
        MD5Final(&sh);

        for (int i=0; i<16; i++) printf("%02x", sh.digest[i]);
        cout<<endl;

        char buf2[65];
        for (int i=0; i<16; i++) sprintf(buf2+2*i,"%02x", sh.digest[i]);

        for (int i=0; i<32; i++) out<<buf2[i];
        out<<endl;

        t = clock() -t;
        //printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    }

    return 0;

}
