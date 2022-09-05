#include<bits/stdc++.h>
using namespace std;
unsigned long long A,B;
int opt;
int main(){
    cin>>opt;
    char ch=getchar_unlocked();
    while(ch<'A'||ch>'Z')ch=getchar_unlocked();
    while(ch!='\n'){
        if(ch=='A')A=A*5+1;
        else if(ch=='T')A=A*5+2;
        else if(ch=='G')A=A*5+3;
        else if(ch=='C')A=A*5+4;
        ch=getchar_unlocked();
    }
    while(ch!=EOF){
        if(ch=='A')B=B*5+2;
        else if(ch=='T')B=B*5+1;
        else if(ch=='G')B=B*5+4;
        else if(ch=='C')B=B*5+3;
        ch=getchar_unlocked();
    }
    printf("%s\n",(A==B)?"Yes":"No");
}