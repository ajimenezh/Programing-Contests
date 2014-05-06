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
#include <stdlib.h>

using namespace std;

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

#define MAXN 2147483648LL
#define BUFSIZE 1048576

unsigned int is[MAXN/16]; // Not sure if bool takes 1 byte or not
unsigned int v[101];
int k;
unsigned int a;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    //FILE *input;
    //input = fopen("C:\\Users\\Alex\\Downloads\\integers\\integers","r");

    fstream input;
    input.open("C:\\Users\\Alex\\Downloads\\integers\\integers", std::ifstream::in);
    fstream out;
    out.open("output.txt", std::ifstream::out);

    streambuf * pbuf = input.rdbuf();

    char buf[BUFSIZE+5];

    int c;
    unsigned int f;
    fpos_t pos;
    for (unsigned int i=0; i<8192; i++) {
        //fread(buf,1,BUFSIZE,input);
        pbuf->pubseekpos(i*BUFSIZE);
        pbuf->sgetn(buf,BUFSIZE);
        //cout<<int(buf[0])<<endl;
        //fgetpos (input, &pos);
        for (int j=0; j<BUFSIZE; j+=4) {
            f = 0;
            for (int r=0; r<4; r++) {
                c = 256 + int(buf[j+r]);
                c %= 256;
                f += (1<<(8*r))*c;
                is[f/(unsigned int)16] |= 1<<(f%(unsigned int)16);
                if (c==-1) {
                    cout<<"ERROR"<<endl;
                    return 0;
                }
            }
            if (f==9854) {
                cout<<"hola";
                cout<<j<<endl;
                cout<<int(buf[j+4+0])<<" "<<int(buf[j+4+1])<<" "<<int(buf[j+4+2])<<" "<<int(buf[j+4+3])<<endl;
                cout<<int(buf[j+8+0])<<" "<<int(buf[j+8+1])<<" "<<int(buf[j+8+2])<<" "<<int(buf[j+4+3])<<endl;
                //int dc; cin>>dc;
            }
            //if (i==1676) cout<<f<<endl;
            if (f==(unsigned int)2147447034) break;
        }
        if (f==(unsigned int)2147447034) break;
        //fsetpos (input, &pos);
        cout<<i<<" "<<f<<endl;
    }

    //fclose(input);
    for (unsigned int i=0; i<(MAXN>>4); i++) {
        for (int j=0; j<16; j++) {
            if ((is[i]&(1<<j))==0) {
                //v[k++] = (unsigned int)(i*(unsigned int)16+j);
                out<<(unsigned int)(i*(unsigned int)16+j)<<"\n";
                cout<<(unsigned int)(i*(unsigned int)16+j)<<"\n";
            }
        }
    }
    cout<<"hola"<<endl;
    cout<<k<<endl;
    for (int i=0; i<k; i++) cout<<v[i]<<endl;

//    int n;
//    scanf("%d",&n);
//    for (int i=0; i<n; i++) {
//        int ind;
//        scanf("%d",&ind);
//        ind--;
//        printf("%d\n",v[ind]);
//    }

    return 0;

}
