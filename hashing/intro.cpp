#include <cstdlib>
#include <iostream>
#include <string>
// #include "hash.h"

using namespace std;

class hash
{
	private:
		static const int tableSize=5;

		struct item
		{
			string name;
			string drink;
			item *next;
		};

		item *hashTable[tableSize];

	public: 
		hash();
		int Hash(string key);
		void AddItem(string name, string drink);
		int numberOfItemsInIndex(int index);
		void printTable();
		void printItemsInIndex(int index);
		void findDrink(string name);
		void deleteItem(string name);

};

hash::hash()
{
	for (int i=0;i<tableSize;i++)
	{
		hashTable[i] = new item;
		hashTable[i]->name="empty";
		hashTable[i]->drink="empty";
		hashTable[i]->next=NULL;
	}
}

int hash::Hash(string key)
{
	int hash=0;
	int index;

	
	for (int i=0; i<key.length();i++)
	{
		hash=17*(hash+(int)key[i]);
	}
	
	index= hash%tableSize;

	return index;

}

void hash::AddItem(string name,string drink)
{
	int index=Hash(name);
	if(hashTable[index]->name=="empty")
	{
		hashTable[index]->name=name;
		hashTable[index]->drink=drink;
	}
	else
	{	
		item *ptr=hashTable[index];
		item *n=new item;
		n->name=name;
		n->drink=drink;
		n->next=NULL;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=n;

	}
}

int hash::numberOfItemsInIndex(int index)
{
	int count=0;
	item *ptr;
	ptr=hashTable[index];
	if (hashTable[index]->name=="empty")
		return count;
	else
	{
		count++;
		while(ptr->next!=NULL)
		{
			count++;
			ptr=ptr->next;
		}
	return count;
	}
}

void hash::printTable()
{
	int number;
	for (int i=0; i < tableSize; i++)
	{
		number=numberOfItemsInIndex(i);
		cout<<"-------------\n"<<"index ="<<i<<endl;
		cout<<hashTable[i]->name<<endl;
		cout<<hashTable[i]->drink<<endl;
		cout<<"number of items:"<<number;
		cout<<"\n-------------\n";
	}
}


void hash::printItemsInIndex(int index)
{
	item *ptr=hashTable[index];
	if(ptr->name=="empty")
		cout<<"index "<<index<<" is empty\n";
	else
	{	
		cout<<"index "<<index<<" contains these: \n";
		while(ptr->next!=NULL)
		{	
			cout<<"**************\n";
			cout<<ptr->name<<endl;
			cout<<ptr->drink<<endl;
			ptr=ptr->next;
			cout<<"*************\n";
		}	
	}	
	
}

void hash::findDrink(string name)
{
	int index=Hash(name);
	item *ptr=hashTable[index];
	while(ptr->next!=NULL)
	{
		if (ptr->name==name)		
		{
			cout<<"drink is "<<hashTable[index]->drink<<endl;
			return;
		}
		else 
			ptr=ptr->next;
	}
	cout<<"invalid name\n";
}

void hash::deleteItem(string name)
{
	int index=Hash(name);
	item *delptr;
	item *ptr=hashTable[index];
	//first node
	if (hashTable[index]->name==name && hashTable[index]->next==NULL)
	{
		hashTable[index]->name="empty";
		hashTable[index]->drink="empty";
	}
	else if (hashTable[index]->name==name)
	{	
		delptr=hashTable[index];
		hashTable[index]=hashTable[index]->next;
		delete delptr;
		// cout<<"trump found!!!!!!!!!\n";
		return;
	}
	//non first
	else
	{
		while(ptr->next!=NULL)
		{ 
			if (ptr->next->name==name)
			{
				ptr->next=ptr->next->next;
				return;
			}
			ptr=ptr->next;
		}		
	}

	
	cout<<"invalid name\n";

}

int main(int argc, char** argv)
{
	hash hashy;
	hashy.AddItem("Ron","beer");
	hashy.AddItem("Ishu","soda");
	hashy.AddItem("Paul","water");
	hashy.AddItem("Ryan","coffee");
	hashy.AddItem("Donald","covfefe");
	hashy.AddItem("Steve","tea");
	hashy.printTable();
	// cout<<"###########################\n";
	// hashy.printItemsInIndex(1);
	string name="";
	while (name!="exit")
	{
		cin>>name;
		hashy.deleteItem(name);
		hashy.printTable();
		// hashy.findDrink(name);
	}
	return 0;
}
