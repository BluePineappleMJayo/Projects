#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int getCompSelection(int compH, string& comH);
int getUserSelection(int userH, string& useH);
int compare(int userH, int compH);
string hand(int);
void playResults(int &winner, int& tie, int& compW, int& userW, string useH, string comH);
void finalResults(int tie, int compW, int userW);

int main()
{
	int compH, userH, tie=0, compW=0, userW=0, winner;
	string comH, useH;
	char ans='y';

	do
	{
		cout<< "It's time to play ROCK, PAPER, SCISSORS!\n";
		userH = getUserSelection(userH,useH);
		compH = getCompSelection(compH,comH);
		winner = compare(userH,compH);
		playResults(winner,tie, compW, userW, useH, comH);
		cout << "Play again? (Y/N): ";
		cin >> ans;
	}while (ans == 'Y' || ans == 'y');
	finalResults(tie, userW, compW);
	return 0;
}
int getCompSelection(int compH, string& comH)
{	
	srand(time(NULL));
	compH = rand () % 3+1;
	comH = hand(compH);
	return compH;
}
int getUserSelection(int userH, string& useH)
{
	cout << "What's your play? \n (1) Rock (2) Paper (3) Scissors : ";
	cin >> userH;
	useH = hand(userH);
	return userH;
}
int compare(int userH, int compH)
{
	if ((userH == 1 && compH == 2) || (userH == 2 && compH == 3) || (userH == 3 && compH == 1) )
	{
		return 1;
	}
	else if(userH == compH)
	{
		return 0;
	}
	else
	{
		return 2;
	}
}
void playResults(int &winner, int& tie, int& compW, int& userW, string useH, string comH)
{
	cout << "You played " << useH << " and I played " << comH;
	switch (winner)
	{
		case 1:
			compW ++;
			cout << "\nI win.";
			break;
		case 0:
			tie ++;
			cout << "\nThe play was a tie.";
			break;
		case 2:
			userW ++;
			cout << "\nYou win.";
			break;
	}
}
void finalResults(int tie, int userW, int compW)
{
	cout << "Final results of our match: "
		<< "\nYou won " << userW << " time(s)."
		<< "\nI won " << compW << " time(s). "
		<<"\nThere were " << tie << " tie(s).";
	cout << "\nBye, bye . . . ";
}
string hand(int userH)
{
	if (userH == 1)
		return "rock";
	else if (userH == 2)
		return "paper";
	else
		return "scissors";
}
