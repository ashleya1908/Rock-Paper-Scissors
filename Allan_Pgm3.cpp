// Ashley Allan, 2228 CS 2010 Section 1004, MoWeFri 11:30am-12:20pm

//Program 3:Rock Paper Scissors, File:AllanA_Pgm3, Due:10/10/2022

/*
Purpose: to play an automated game of Rock, Paper, Scissors. Two players make one of three
hand signals at the same time. Hand signals represent a rock, a piece of paper, or a pair of scissors. Each
combination results in a win for one of the players. Rock crushes scissors, paper covers rock, and scissors
cut paper. A tie occurs if both players make the same signal.
Input: Player names, number of rounds, signal choice, choice to play again
Processing: If-else statements are nested into for, while, and do-while loops in order to choose the sign
and calculate the outcome of the game. The variable that holds the win number for each player is incremented.
Output: The game process, player names, and amount of wins is output at the conclusion of the rounds. Players
are asked if they would like to play again.

Reflection: I struggled a lot in this chapter. I tried to get the extra credit for this program, but I was only 
successful in half of the parameters. I feel that this chapter was extremely tough but ultimately I got through it
and was able to have success in writing this program. 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;
int main() {

	srand(time(NULL));

const int ROCK = 0;
const int PAPER = 1; //Variables for choices
const int SCISSORS = 2;

string player1First;
string player1Last;
string player2First; //Variables for player names
string player2Last;

string playAgain = "YES"; //Variable to play again

char name1; //Variables used to change name format
char name2;

int numRounds; // Variable for number of rounds

int p1Choice = 0;
int p2Choice = 1;
int win1 = 0; //Variables for player wins
int win2 = 0;

while (playAgain == "YES") { //Loop that repeats when input is "YES"
	cout << "Enter player's first and last name: " << endl;
	cin >> player1First >> player1Last;
	cout << "Enter another player's first and last name: " << endl; //gathers first name and last name of both players, and number of rounds
	cin >> player2First >> player2Last;
	cout << "Enter number of rounds: " << endl;
	cin >> numRounds;
	
	if (numRounds < 0) {
		cout << "Rounds must be > 0" << endl;
		cin >> numRounds;
	}
	
	else { //Changes naming format from given input
		name1 = player1First.front();
		name2 = player2First.front();
		cout << name1 << player1Last << " vs ";
		cout << name2 << player2Last << " for " << numRounds << " rounds" << endl;
		

	}
	for (int i = 0; i < numRounds; i++) { //Loop repeats as many times as input from numRounds
	
		do {
			p1Choice = rand() % 3;
			p2Choice = rand() % 3; 
		
			//Calculates outcome based on choice:
			if (p1Choice == ROCK && p2Choice == SCISSORS) { //Conditions for player 1 to win
				cout << name1 << player1Last << " wins with rock" << endl;
				win1 = win1 + 1; //Increments number of wins for player 1
			}
			else if (p1Choice == PAPER && p2Choice == ROCK) {
				cout << name1 << player1Last << " wins with paper" << endl;
				win1 = win1 + 1; 
			}
			else if (p1Choice == SCISSORS && p2Choice == PAPER) {
				cout << name1 << player1Last << " wins with scissors" << endl;
				win1 = win1 + 1;
			} //Conditions for player 2 to win
			else if (p1Choice == SCISSORS && p2Choice == ROCK) {
				cout << name2 << player2Last << " wins with rock" << endl;
				win2 = win2 + 1;
			}
			else if (p1Choice == ROCK && p2Choice == PAPER) {
				cout << name2 << player2Last << " wins with rock" << endl;
				win2 = win2 + 1;
			}
			else if (p1Choice == PAPER && p2Choice == SCISSORS) {
				cout << name2 << player2Last << " wins with rock" << endl;
				win2 = win2 + 1;
			} 

			if (p1Choice == p2Choice) {
				cout << "Tie" << endl;
			}
	} while (p1Choice == p2Choice);
}

	
	cout << name1 << player1Last << " wins " << win1 << " "; //Outputs player names and final win counts 
	cout << name2 << player2Last << " wins " << win2 << endl;
	
	win1 = 0;
	win2 = 0;
	name1 = ' ';
	name2 = ' '; //Resets all variables for the next game
	player1First = "";
	player2First = "";
	player1Last = "";
	player2Last = "";
	
	cout << "Play another game? (YES, NO)"; //prompts input to play another game 
	cin >> playAgain;
	if ((playAgain != "YES") && (playAgain != "NO")) {
		cout << "Please answer with YES or NO" << endl;
		cin >> playAgain;
	}
	else {
	}
}
return 0;
}
