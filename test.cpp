#include <iostream>
using namespace std;
class ParentClass{
    public:
    int var1=100;
};

class ChildClass : public ParentClass{
    public:
    int var2 = 500;
    ChildClass(){
        var2= 200;
        var1=22;
    }
};


int main(void){
    ChildClass obj;
    cout<<obj.var1<<endl;
    cout<<obj.var2<<endl;
}