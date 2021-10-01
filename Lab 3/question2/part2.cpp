#include <iostream>

class Nest;
class Egg;

class Hen
{
    public:
        void display();
        class Nest;
        class Egg;
};

class Nest
{  
    int Nestpriv = 2; // change this value to get a different output
    public:
        void display(Egg a);
        friend class Egg;
        int getValue(Egg a);
};

class Egg
{
    int Eggpriv = 5; // change this value to get a different output
    public:
        void display(Nest b);
        friend class Nest;
        int getValue(Nest b);

};

void Hen::display()
{
    std::cout<<("Display Hen")<<std::endl;
}

int Nest::getValue(Egg a)
{
    int eggValue = a.Eggpriv;
    return eggValue;
}

void Nest::display(Egg a)
{
    std::cout<<("Display Nest: ")<< getValue(a) << std::endl;
}

int Egg::getValue(Nest b)
{
    int nestValue = b.Nestpriv;
    return nestValue;
}

void Egg::display(Nest b)
{
    std::cout<<("Display Egg: ")<< getValue(b) << std::endl;
}


int main()
{
    //need to find exercise6 to even attempt to modify
    Hen ChickenHen;
    Nest ChickenNest;
    Egg ChickenEgg;

    ChickenHen.display();    
    ChickenNest.display(ChickenEgg);    
    ChickenEgg.display(ChickenNest);

    
    return 0;
}

//https://www.cplusplus.com/doc/tutorial/inheritance/ helped me figure out friends
