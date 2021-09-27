#include <iostream>

class Hen
{
    public:
        void display();
        class Nest
        {  
       
            public:
                void display();

            class Egg
            {
             
                public:
                    void display();

            };
        };
    
};

void Hen::display()
{
    std::cout<<("Display Hen")<<std::endl;
}

void Hen::Nest::display()
{
    std::cout<<("Display Nest")<<std::endl;
}

void Hen::Nest::Egg::display()
{
    std::cout<<("Display Egg")<< std::endl;
}

int main()
{
    //my attempt at exercise6
    Hen Chicken;
    Hen::Nest Chicken2;
    Hen::Nest::Egg Chicken3;

    Chicken.display();    
    Chicken2.display();    
    Chicken3.display();

    
    return 0;
}