/*
Author:ShuoCHN
Date:2018-1-13

this is a program to storage the cost in Jia Musi.
Qdacm Version

commands:

NewCost -> record a new cost
ShowBalance -> show the balance of everybody sort by ind
ShowStream -> show the stream of everybody sort by ind
End -> close the program




*/

#include<iostream>
#include<algorithm>
#include<queue> 
#include<map>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

const int DALAONUM=10;
map<string,int> ind;

int peonum;


string doutostr(double input)
{
	stringstream oss;
	oss<<input;
	return oss.str();
}

class people{
	public:
		string name;
		vector<string> cost_stream;
		double balance=0;
		
		void balance_up(double x)
		{
			balance+=x;
		}
		
		void balance_cost(double x,string des,string date)
		{
			balance-=x;
			string save="Date: "+date+" cost "+doutostr(x)+" yuan for "+des;
			cost_stream.push_back(save);
		}
	
}dalao[DALAONUM];



void set_map_ind() //ind[name]->get the index of class->dalao
{
	cout<<"input the name,bal,each line for two:"<<endl;
	for(int i=1;i<=peonum;i++)
	{
		string temp;
		double bal=0;
		cin>>temp;
		ind[temp]=i;
		dalao[i].name=temp;
		cin>>bal;
		dalao[i].balance_up(bal);
	}
}





void newcost()
{
	
	int peo_num_inside=peonum;
	string date,des;
	cout<<"input the date and des: ";
	cin>>date>>des;
	
	double cost_all=0;
	cout<<"input the cost_all: ";
	cin>>cost_all;
	
	string dif;
	
	cout<<"has any difference[Y/N]: ";
	cin>>dif;
	
	bool cnt_dont[DALAONUM];
	memset(cnt_dont,0,sizeof(cnt_dont));
	
	if(dif=="N")
	{
		double average=cost_all/peonum;		
		for(int i=1;i<=peonum;i++)
		{
			dalao[i].balance_cost(average,des,date);
		}
	}		

	
	
	else if(dif=="Y")
		while(1)
		{
			string com;
			cout<<"input the com of difference: ";
			cin>>com;
			
			if(com=="end") 
			{
				double average=cost_all/peo_num_inside;	
				//cout<<"testpoint 1"<<endl;
				for(int i=1;i<=peonum;i++)
				{
					//cout<<"testpoint 2"<<" --"<<i<<endl;
					if(!cnt_dont[i])
					{
						dalao[i].balance_cost(average,des,date);
						//cout<<"testpoint 3"<<" --"<<cnt<<endl;
					}
						
				}
				break;
			}
			
			if(com=="more")
			{
				string name;
				cin>>name;
				double money;
				cin>>money;
				string ass=des+"more**";
				dalao[ind[name]].balance_cost(money,ass,date);
				
				cost_all-=money;
				
			}
			if(com=="less")
			{
				string name;
				cin>>name;
				double money;
				cin>>money;
				string ass=des+"less return**";
				dalao[ind[name]].balance_cost(0-money,ass,date);
				
				cost_all+=money;
			}
			if(com=="out")
			{
				string name;
				cin>>name;
				cnt_dont[ind[name]]=1;
				peo_num_inside-=1;
			}
			
			
		
		}
	
	
	
}

void showbalance()
{
	cout<<"-------------------------------"<<endl;
	cout<<"Balance: "<<endl;
	for(int i=1;i<=peonum;i++)
	{ 
		cout<<dalao[i].name<<"'s balance: "<<dalao[i].balance<<endl;
	}
	cout<<"-------------------------------"<<endl;
}


void showstream()
{
	for(int i=1;i<=peonum;i++)
	{ 
		cout<<"-----------------------------"<<endl;
		cout<<dalao[i].name<<": "<<endl;
		vector<string>::iterator it;
		for(it=dalao[i].cost_stream.begin();it!=dalao[i].cost_stream.end();it++)
			cout<<*it<<endl;
		if(i!=peonum)
			cout<<"*****************************"<<endl;
	}
	cout<<"-----------------------------"<<endl;
}


void recharge()
{
	cout<<"input name and money: ";
	string name;
	double money;
	cin>>name>>money;
	dalao[ind[name]].balance_up(money);
	cout<<"charge finished."<<endl;
	
}








void user_input()
{
	cout<<"input the peonum:";
	cin>>peonum;
	set_map_ind();
	
	while(1)
	{
		//input the commmands
		cout<<endl;
		cout<<"input the com: ";
		string com;
		cin>>com;
		
		if(com=="End") break;//close the program
		else if(com=="NewCost") newcost();
		else if(com=="ShowBalance") showbalance();
		else if(com=="ShowStream") showstream();
		else if(com=="Recharge") recharge();
		
	}
	
}

void debugger()
{
	user_input();
	
}


int main()
{
	debugger();
	
	
	return 0;
}


