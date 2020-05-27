#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int i,j,n;
void gross_sal(int);
void details(int);
void sort();
void hig_tax();
void low_tax();
struct employee
{
	char name[10];
	int id;
	int grade;
	int basic,gross,net,da,hra,tax;
}s[10],temp;
void main()
{
	cout<<"Enter the number of emplouyee"<<endl;
		cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the details of"<<i+1<<"employee:"<<endl;
	    cout<<"name";
		cin>>s[i].name;
		cout<<"ID"<<endl;
		cin>>s[i].id;
		cout<<"grade(1-4)"<<endl;
		cin>>s[i].grade;
		cout<<"DA"<<endl;
		cin>>s[i].da;
		cout<<"HRA"<<endl;
		cin>>s[i].hra;
	}
	for(i=0;i<n;i++)
	{
		cout<<"Details of the"<<i+1<<"employees";
		cout<<"name"<<s[i].name<<endl;
		cout<<"ID"<<s[i].id<<endl;
		cout<<"GRADE"<<s[i].grade<<endl;
		s[i].basic=gross(s[i].grade);
		s[i].gross=s[i].basic+s[i].da+s[i].hra;
		if(s[i].gross<20000)
		{
			s[i].net=s[i].gross;
		}
		else if(s[i].gross>=20000&&s[i].gross<=30000)
		{
			s[i].tax=0.10*s[i].gross;
			s[i].net=s[i].gross-s[i].tax;
		}
		else if(s[i].gross>30000)
		{
			s[i].tax=0.15*s[i].gross;
			s[i].net=s[i].gross-s[i].tax;
		}
		cout<<"tax paid"<<s[i].tax<<endl;
		cout<<"net salary"<<s[i].net<<endl;
	}
	int ch,g;
	for(;;)
	{
		cout<<"1.sort"<<endl<<"2.Print Details According to details"<<endl<<"3.Highest Tax"<<endl<<"4.Lowest Tax"<<endl<<"5.Exit"<<endl;
		cout<<"Enter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1 : sort();
			break;
		case 2 : cout<<"enter the grade";
			cin>>g;
			break;
		case 3 : hig_tax();
			break;
		case 4 : low_tax();
			break;
		}
	}
}
int gross(int grade)
{
	int basic;
	{
		if(grade==1)
		{
			basic=30000;
		}
		else if(grade==2)
		{
			basic=25000;
		}
		else if(grade==3)
		{
			basic=20000;
		}
		else 
		{
			basic=15000;
		}
		return basic;
	}
}
void sort()
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].id>s[j].id)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	cout<<"The sorted details are";
	for(i=0;i<n;i++)
		{
			cout<<"Name"<<s[i].name<<endl;
			cout<<"Id"<<s[i].id<<endl;
			cout<<"NET Salary"<<s[i].net<<endl;
		}
}
void details(int grade)
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].id>s[j].id)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}for(i=0;i<n;i++)
		if(grade==s[i].grade)
	{
		cout<<"Details of same grade"<<grade<<"employee";
		cout<<"Name"<<s[i].name<<endl;
		cout<<"ID"<<s[i].id<<endl;
		cout<<"Net salary"<<s[i].net<<endl;
	}
}
void hig_tax()
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].tax<s[j].tax)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	cout<<"The sorted details are";
		for(i=0;i<n;i++)
		{
			cout<<"Name"<<s[n-1].name<<endl;
			cout<<"Id"<<s[n-1].id<<endl;
			cout<<"NET Salary"<<s[n-1].net<<endl;
		}
}
void low_tax()
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].tax<s[j].tax)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	cout<<"The sorted details are";
		for(i=0;i<n;i++)
		{
			cout<<"Name"<<s[0].name<<endl;
			cout<<"Id"<<s[0].id<<endl;
			cout<<"NET Salary"<<s[0].net<<endl;
		}
}