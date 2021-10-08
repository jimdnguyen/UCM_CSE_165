#include <iostream>

class Subject{
    public:

    virtual void f(){
        std::cout<<"This print is for function f in Subject"<<std::endl;
    }
    virtual void g(){
        std::cout<<"This print is for function g in Subject"<<std::endl;
    }
    virtual void h(){
        std::cout<<"This print is for function h in Subject"<<std::endl;
    }
};
class Implementation1 : public Subject{
    public:

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
    public:
    
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
        ptrSubject->g();
    }
    void h(){
        ptrSubject->h();
    }       

    void change(Subject* tmpPtrSubject){
        ptrSubject = tmpPtrSubject;
    }
    
    Proxy(Subject* secPtrSubject) : Subject() , ptrSubject(secPtrSubject){};
};

int main(){

    Implementation1 implem1;
    Implementation2 implem2;

    Proxy pxy(&implem1);

    pxy.f(); 
    pxy.g();
    pxy.h();

    pxy.change(&implem2);
    std::cout<<std::endl;

    pxy.f(); 
    pxy.g();
    pxy.h();

    return 0;
}