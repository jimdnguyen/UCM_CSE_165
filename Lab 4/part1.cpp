#include <iostream>

class Subject{
    public:
    
    void f(){
        std::cout<<"This print is for function f in Subject"<<std::endl;
    }
    void g(){
        std::cout<<"This print is for function g in Subject"<<std::endl;
    }
    void h(){
        std::cout<<"This print is for function h in Subject"<<std::endl;
    }
};
class Implementation1 : public Subject{
    void f(){
        std::cout<<"This print is for function f in Implemention1"<<std::endl;
    }
    void g(){
        std::cout<<"This print is for function g in Implemention1"<<std::endl;
    }
    void h(){
        std::cout<<"This print is for function h in Implemention1"<<std::endl;
    }
};
class Implementation2 : public Subject{
    void f(){
        std::cout<<"This print is for function f in Implemention2"<<std::endl;
    }
    void g(){
        std::cout<<"This print is for function g in Implemention2"<<std::endl;
    }
    void h(){
        std::cout<<"This print is for function h in Implemention2"<<std::endl;
    }
};

class Proxy : public Subject{
    Subject* ptrSubject;

    public:
    
    void f(){
       ptrSubject->f();
    }
    void g(){

    }
    void h(){
        
    }       
    
        Proxy(Subject* realSubject);
};

Proxy::Proxy(Subject* realSubject){
    ptrSubject = realSubject;
}


int main(){

    Implementation1 implem1;
    Implementation2 implem2;

    Proxy pxy(&implem1);

    pxy.f();

    //math2.Implementation1;

    return 0;
}