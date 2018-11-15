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
                else if(strcmp(p,"pingguo") == 0)
                {
                        return new Apple;
                }
                else
                {
                        cout<<"该工厂不生产该产品"<<endl;
                        return NULL;
                }
        }
};

int main()
{
        Factory *factory = new Factory();
        Fruit *fruit ;
        fruit = factory->create("pingguo");
        if(fruit != NULL)
        {
                fruit->getFruit();
        }
        delete fruit;
        fruit = factory->create("xianjiao");
        if(fruit != NULL)
        {
                fruit->getFruit();
        }
        delete fruit;
        fruit = factory->create("boluo");
        if(fruit != NULL)
        {
                fruit->getFruit();
        }
        delete fruit;
        delete factory;
        return 0;
}
