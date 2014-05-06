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

unsigned int is[MAXN/16];
unsigned int v[101];
int k;
unsigned int a;
unsigned int buf[100000000/4];

    //****************************************************
    //          Code to precalculate de 100 numbers
    // It isn't completely neccessary but makes the submit faster

void precalculate() {

    string dir = "C:\\Users\\Alex\\Downloads\\integers\\integersv";

    FILE * input;

    for (int i=0; i<85; i++) {
        string name = dir;
        if (i+2>=10) name += char('0' + (i+2)/10);
        name += char('0' + (i+2)%10);

        input = fopen(name.c_str(),"r");
        fread(buf,4,100000000,input);
        fclose(input);
        unsigned int c;
        for (int j=0; j<100000000/4; j++) {

            is[buf[j]/16] |= 1<<(buf[j]%16);

        }

    }
    string name = dir;
    name += char('0' + 87/10);
    name += char('0' + 87%10);

    input = fopen(name.c_str(),"r");
    fread(buf,4,89934192,input);
    fclose(input);
    unsigned int c;
    for (int j=0; j<22483548; j++) {

        is[buf[j]/16] |= 1<<(buf[j]%16);
    }

    for (unsigned int i=0; i<(MAXN>>4); i++) {
        for (int j=0; j<16; j++) {
            if ((is[i]&(1<<j))==0) {
                cout<<(unsigned int)(i*(unsigned int)16+j)<<"\n";
            }
        }
    }
}

int main() {

    ifstream input;
    input.open("C:\\Users\\Alex\\Downloads\\datos(2).txt");

    for (int i=0; i<100; i++) input>>v[i];

    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int ind;
        scanf("%d",&ind);
        ind--;
        printf("%d\n",v[ind]);
    }

    return 0;

}
