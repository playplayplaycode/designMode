#include <iostream>
#include <string>

using namespace std;

class Memento
{
public:
	Memento(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}
private:
	string m_name;
	int m_age;
};
class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age  = age;
	}
	string getName()
	{
		return this->m_name;
	}
	int getAge()
	{
		return this->m_age;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}
	Memento* createMemento()
	{
		return new Memento(m_name,m_age); 

	}
	void setMemento(Memento *memento)
	{
		this->m_name = memento->getName();
		this->m_age = memento->getAge();
	}
	void printT()
	{
		cout<<m_name<<":"<<m_age<<endl;
	}
private:
	string m_name;
	int m_age;
};

class Caretaker
{
public:
	Caretaker(Memento *memento)
	{
		this->m_memento = memento;
	}
	Memento* getMemento()
	{
		return this->m_memento;
	}
	void setMemento(Memento *memento)
	{
		this->m_memento = memento;
	}
private:
	Memento *m_memento;
};

int main()
{
	Person *person = new Person("小高",27);
	person->printT();


	Caretaker *caretaker = new Caretaker(person->createMemento());

	person->setName("小秦");

	person->printT();

	person->setMemento(caretaker->getMemento());

	person->printT();

	delete caretaker;
	delete person;
}

