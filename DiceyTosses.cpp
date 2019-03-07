#include <iostream>
#include <ctime>

using namespace std;

void rollDie(int n, int die1[]);
void findSum(int n, int die1[], int die2[], int sumTally[13]);
//Postcondition: Saves the tally of how many times a sum is hit in sumTally in same index i.e. the tally of the sum of 2 is saved in index 2, tally of 3 in index 3,, up to sum of 12 in index 12
void tossCount(int n,int sumTally[13],float prob[13]);
//checks the probaibility sum given the times it happened in the number of rolls entered by the user,, times it landed on that sum/total rolls into prob
void display(int sumTally[], float prob[13]);
//Tells us the counts of the sums, and the probailities given to us from tossCount

int main()
{
	char ans = 'y';
	srand(time(NULL));
	do{	
		int n;
		cout << "How many rolls would you like to do? :";
		cin>> n;
		int die1[n],die2[n],sumTally[13]={};
		float prob[13];
		rollDie(n,die1);
		rollDie(n,die2);
	
		findSum(n,die1,die2,sumTally);
		tossCount(n,sumTally,prob);
	
		display(sumTally,prob);
		cout << "Want to go again? (Y/N)";
		cin >> ans;
	}while(ans == 'Y' || ans == 'y');
}
void rollDie(int n, int die1[])
{
	int i;
	for(i=0; i<n; i++)
	{
		die1[i] = rand()%6+1;
	}
}
void findSum(int n, int die1[],int die2[], int sumTally[])
{
	int i,x;
	for(i=0;i<n;i++)
	{
		x=die1[i]+die2[i];
		sumTally[x]++;
	}
}
void tossCount(int n, int sumTally[],float prob[])
{
	int i;
	for(i=2;i<13;i++)
	{
		prob[i]= (sumTally[i]*100.0)/n;
	}
}
void display(int sumTally[], float prob[])
{
	int i;
	cout<< "Toss\tCount\tProbability\n";
	for(i=2; i<13; i++)
	{
		cout<< i << "\t" << sumTally[i] << "\t" << prob[i]<<endl;
	}
}
