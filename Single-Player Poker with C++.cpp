/*
	Name: Karthik Malyala
	Date: 04/15/2020
	Program Description: Using OOP concepts in C++, this lab compiles a single player Poker game with a Base Class and Class Methods.
						 The user starts with 100 chips ($1.00 each) and is given a randomized hand of four cards from a deck of 36 cards.
						 Winning possibilities include 4ofAKind, Straight Flush, Flush, Straight, 3ofAKind, Two Pair, Pair, and Bubkiss. This
						 can be played as long as the user wishes to play and has enough chips. A Final report will be generated with amount of
						 wins, losses, hands, and net winnings.
*/

#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>

using namespace std;
//Poker Superclass with all methods and arrays
class Poker
{
	public:
		int num [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		char suit[4] ={'C', 'S', 'H', 'D'};
		int n[4];
		char s[4];
		int bank;
		int bet;
		int count;
		int wins;
		int losses;
		int net;
		
		Poker();
		void displayHand();
		int checkWin();
};

int main(){
	Poker poker;
	poker.displayHand();
}

Poker :: Poker()
{
	bank = 100;
	bet = 0;
	count = 0;
	wins = 0;
	losses = 0;
	net = 0;
}
// Function that displays the hand, every win/loss, and generates the final report
void Poker :: displayHand()
{
	Poker poker;
	char inp;
	int stop = 0;
	cout<<"Welcome to single player Poker game!"<<endl;
	cout<<"Your initial bank roll is $100.00"<<endl;
	
	do
	{
		cout<<"---------------------------------------------"<<endl;
		cout <<"Play a hand [y/n]?"<<endl;
		cin >> inp;
		if (bank == 0){
			cout <<"You have used up all your chips. Sorry!"<<endl;
			inp = 'n';
		}
		if (inp == 'y'){
			count++;
			cout<<"Place your bet[1, "<<bank<<"]:"<<endl;
			cin >> bet;	
			if (bet <= bank && bet >= 1){
				cout << "...Shuffling Deck..."<<endl;
				cout << "Let the cards fall where they may..."<<endl;
				srand(time(NULL));
				for (int i = 0; i < 4; i++){
					n[i]=num[rand()%9];
					s[i]=suit[rand() % 4];
					cout << n[i] << s[i] << " ";
				}
				checkWin();
				stop = 0;
			}
			else{
				count--;
				cout<<"Invalid Amount. Please try again."<<endl;
			}
			
		}
		else if (inp == 'n'){
			net = bank - 100;
			cout<<"Thanks for playing..."<<endl;
			cout<<"You played a total of "<<count<<" hands"<<endl;
			cout<<"Of which you won "<<wins<<""<<endl;
			cout<<"And you lost "<<losses<<""<<endl;
			cout<<"But in the end you won $"<<net<<""<<endl;
			stop = 1;
		}
		else{
			cout<<"Invalid Choice. Please choose again."<< endl;
		}
	}
	while (stop == 0);
	
}
// Checks for different winning possibilities 
int Poker :: checkWin()
{
	//4ofAKind
	if (n[0]==n[1] && n[0] == n[2] && n[0] == n[3])
	{
		wins++;
		bank += (400 * bet);
		cout <<endl<< "Congrats: You got a 4ofAKind and have won $400 for every chip you placed!"<<endl;
	}
	// Flush
	else if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3])
	{
		wins++;
		int temp;
		int temp2;
		for (int t = 0; t<3; t++){
			temp = t;
			for (int j = t+1;j<4;j++){
				if (n[j]<n[temp])
				{
					temp=j;
				}
			}
			temp2 = n[t];
			n[t]=n[temp];
			n[temp]=temp2;
		}
		// Straight Flush
		if (1+n[0]==n[1] && 1+n[1] == n[2] && 1+n[2] == n[3])
		{
			bank += (300 * bet);
			cout << endl<<"Congrats: You got a Straight Flush and have won $300 for every chip you placed!"<<endl;
		}
		else {
			// Flush
	 		bank += (250 * bet);
			cout << endl<<"Congrats: You got a Flush and have won $250 for every chip you placed!"<<endl;
		}
	}
	//Straight	
	else if ((s[0]!=s[1])||(s[0]!=s[2])||(s[0]!=s[3])||(s[1]!=s[2])||(s[1]!=s[3])||(s[2]!=s[3]))
	{
		int temp;
		int temp2;
		for (int t = 0; t<3; t++){
			temp = t;
			for (int j = t+1;j<4;j++){
				if (n[j]<n[temp])
				{
					temp=j;
				}
			}
			temp2 = n[t];
			n[t]=n[temp];
			n[temp]=temp2;
		}
		if (1+n[0]==n[1] && 1+n[1] == n[2] && 1+n[2] == n[3])
		{
			wins++;
			bank += (200 * bet);
			cout <<endl<< "Congrats: You got a Straight and have won $200 for every chip you placed!"<<endl;
		}
	}
	// 3ofAKind
	if ((n[0]==n[1] && n[0]==n[2]) || (n[0]==n[2] && n[0]== n[3]) || (n[1]==n[2] && n[1]==n[3])||(n[0]==n[1]&&n[0]==n[3]))
	{
		wins++;
		bank += (150 * bet);
		cout << endl<<"Congrats: You got a 3ofAKind and have won $150 for every chip you placed!"<<endl;
	}
	//Two Pair & Pair
	else if((n[0]==n[1])||(n[0]==n[2])||(n[0]==n[3])||(n[1]==n[2])||(n[1]==n[3])||(n[2]==n[3]))
	{
		if ((n[0]==n[1])&&(n[2]==n[3]))
		{
			wins++;
			bank += (100 * bet);
			cout << endl<<"Congrats: You got a Two Pair and have won $100 for every chip you placed!"<<endl;
		}
		else if ((n[1]==n[2])&&(n[0]==n[3]))
		{
			wins++;
			bank += (100 * bet);
			cout <<endl<< "Congrats: You got a Two Pair and have won $100 for every chip you placed!"<<endl;
		}
		else if ((n[0]==n[2])&&(n[1]==n[3]))
		{
			wins++;
			bank += (100 * bet);
			cout << endl<<"Congrats: You got a Two Pair and have won $100 for every chip you placed!"<<endl;
		}
		//Pair
		else{
			wins++;
			bank += (1 * bet);
			cout << endl<< "Congrats: You got a Pair and have won $1 for every chip you placed!"<<endl;
		}
	}
	//All else is BubKiss
	else{
		losses++;
		bank -= bet;
		cout <<endl<<"Sorry: you got Bubkiss and have lost $"<<bet<<""<<endl;
	}	 
}
