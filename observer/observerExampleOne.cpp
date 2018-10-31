#include <iostream>
#include <string>
#include <list>

using namespace std;

class Player
{
public:
        void execCoach(string commond)
        {
                cout<<commond<<endl;
                cout<<"好的，我们收到命令"<<endl;
        }
};


class Coach
{
public:
        void sendCommond(string commond)
        {
                for(list<Player *>::iterator it = m_list.begin(); it != m_list.end() ; it++)
                {
                        (*it)->execCoach(commond);
                }
        }

        void setPlayer(Player *o)
        {
                m_list.push_back(o);
        }
private:
        list<Player *> m_list; 
};


int main()
{
        Coach *Kolpp;
        Player *Mane,*Salah;
        Kolpp = new Coach();
        Mane = new Player();
        Salah = new Player();
        Kolpp->setPlayer(Mane);
        Kolpp->setPlayer(Salah);
        Kolpp->sendCommond("给我全线压上");
        Kolpp->sendCommond("行了，都赢了三个球了，稳了，退回来，龟缩防守吧，为下场比赛保留体力");
        delete Salah;
        delete Mane;
        delete Kolpp;
        return 1;
}
