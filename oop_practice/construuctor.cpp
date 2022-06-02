#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class a
{
    public:
    int x;
    public:
    a(){
    x=5;
    }
};
class b{
    public:
    int y;
    public:
    b(){
    y=10;
    }
};
class c{
    public:
    a p;
    b q;
    int z;
    public:
    c(){
        z=15;
    }
    void show() 
    {
        cout<<p.x;
        cout<<q.y;
        cout<<z;
    }
};

int main()
{
    c r;
    r.show();
}