#include <iostream>
#include <list>
#include <string.h>

using namespace std;

class Command;
//这个类作为观察者的抽象基类
class Player 
{
public:
	Player(string name,Command *command)
	{
		this->name = name;
		this->m_command = command;
	}
	virtual void execCommand(string content) = 0;
	string Name()
	{
		return name;
	}
protected:
	string name;
	Command *m_command;

};


class Forward:public Player
{
public:
	Forward(string name,Command *command):Player(name,command)
	{
	}
	void execCommand(string content);
};

class Guard:public Player
{
public:
	Guard(string name,Command *command):Player(name,command)
	{
	}
	void execCommand(string content);
};

class Command
{
public:
        virtual void attach(Player *player) = 0;
	virtual void detach(Player *player) = 0; 
	virtual void notify(string content) = 0;
protected:
        list<Player *> m_list;
};

class CoachCommand:public Command
{
public:
	void attach(Player *player)
	{
		m_list.push_back(player);
	}
	void detach(Player *player)
	{
		list<Player *>::iterator item = m_list.begin();
		while(item != m_list.end())
		{
			if((*item) == player)

			{
				cout<<player->Name()<<"被换下场"<<endl;
				item = m_list.erase(item);
							
			}
			else
				++item;
		}
	}
	void notify(string content)
	{
		list<Player *>::iterator it;
		for(it = m_list.begin() ; it != m_list.end() ; it ++)
		{
			(*it)->execCommand(content);
		}
	}
};

void Forward::execCommand(string content)
{
	if(content == "开始强攻")
		cout<<name<<"收到："<<content<<"的指令，然后采取："<<"开启疯抢模式的战术"<<endl;
	if(content == "开始防守")
		cout<<name<<"收到："<<content<<"的指令，然后采取："<<"回到本方半场进行防守，伺机进行反击的战术"<<endl;
}


void Guard::execCommand(string content)
{
	if(content == "开始强攻")
		cout<<name<<"收到："<<content<<"的指令，然后采取："<<"往前提防线，保持高压态势的战术"<<endl;
	if(content == "开始防守")
		cout<<name<<"收到："<<content<<"的指令，然后采取："<<"龟缩到禁区附近，进行全力防守的战术"<<endl;
}


int main()
{
	CoachCommand *Kolpp;
	Forward *Salah,*Mane;
	Guard *vanDijk,*Matip;
	Kolpp = new CoachCommand();
	Salah = new Forward("萨拉赫",Kolpp);
	Mane = new Forward("大马内",Kolpp);
	vanDijk = new Guard("范戴克",Kolpp);
	Matip = new Guard("马蒂普",Kolpp);
	Kolpp->attach(Salah);
	Kolpp->attach(Mane);
	Kolpp->attach(vanDijk);
	Kolpp->attach(Matip);
	Kolpp->notify("开始强攻");
	cout<<"比赛进行到75分钟，利物浦已经3:0领先！"<<endl;
	
	Kolpp->detach(vanDijk);
	Kolpp->notify("开始防守");
	delete Matip;
	delete vanDijk;
	delete Mane;
	delete Salah;
	delete Kolpp;

};




