#include <iostream>

#include <string.h>
using namespace std;

class Fruit
{
        public:
        virtual void getFruit() = 0;
};

class Banana:public Fruit
{
        public:
        virtual void getFruit()
        {
                cout<<"香蕉"<<endl;
        }
};

class Apple:public Fruit
{
        public:
        virtual void getFruit()
        {
                cout<<"苹果"<<endl;
        }
};

class Factory
{
        public:
        Fruit* create(char* p)
        {
                if(strcmp(p,"xianjiao") == 0)
                {
                        return new Banana;
                }
                if(strcmp(p,"pingguo") == 0)
                {
                        return new Apple;
                }
        }
};

int main()
{
        Factory *factory = new Factory();
        Fruit *fruit ;
        fruit = factory->create("pingguo");
        fruit->getFruit();
        return 0;
}
