#include <iostream>
using namespace std;

int _stack[100];
int fn;

int ebp;
int esp;
int edi;
int esi;
int ebx;
int eax;
int *edi2;

int main() {

    _stack[fn++] = ebp;

    ebp = esp;

    _stack[fn++] = edi;
    _stack[fn++] = esi;
    _stack[fn++] = ebx;

    esp = esp - 0x10;

    eax = ebp + 0x4;
    edi2 = &ebp + 0x8;

    ebp = eax + 0x10;

    edx = edx ^ edx;

    eax = 0x1A;
    ebx = edx;
    ecx = edx;
    esi = edx;

}
