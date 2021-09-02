#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
const int Num = 5;
int i,j,min1;
double total[5];
void readBankRec();
void detBankruptcy(int,int);
struct record
{
	string bankname;
	int bal1;
	string lend1 ;
	int ballend1 ;
	string lend2 ;
	int ballend2 ;
};


int main()
{
	
	readBankRec();
	cout << "Enter Min Asset Limits: ";
	cin >> min1;
	detBankruptcy(min1,i);
	

	return 0;
}

void readBankRec()
{
	ifstream inFile;
	string filename;

	
	cout << "Please enter the name of the file you wish to open : ";
	cin >> filename;
	
	inFile.open(filename.c_str());
	
	if (inFile.fail())
	{
		cout << "\nThe file was not successfully opened"
			 << "\n Please Check that the file exists"
			 << endl;
		exit(1);
	}
	cout << "\nThe file has been automatically open for reading "
		 << endl;
		 
	return;
	
}

void detBankruptcy(int min1 , int i)
{
	record bank[Num]={  { "C",40,"A",110.5,"E",320.5},
						{ "A",124,"B",265.5,"D",40},
						{ "D",75,"C",28,"E",12},
						{ "B",67,"D",75,"E",35},
						{ "E",181,"B",125,"A",210.5} };
						
	for(i=0;i<Num;i++)
	{
		total[i]=bank[i].bal1 + bank[i].ballend1 + bank[i].ballend2;
	if (total[i]<min1)
	{
		for (i=0;i <Num ; i++)
		cout << bank[i].bankname << total[i] << " You are Bankrupt";
		cout << endl;
	}
	else
	{
		for (i=0;i <Num ; i++)
		cout << bank[i].bankname << total[i] << " You are save";
		cout << endl;	
	}
	
	}
						
	return ;				
}
