#include <iostream>
#include <String>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();


int main()
{
	PrintIntro();
	PlayGame();
	return 0; //exit application
}

void PrintIntro()
{
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame()
{
	//loop  for number of guesses
	constexpr int NUMBER_TURNS = 5;
	for (int Count = 1; Count <= NUMBER_TURNS; Count++)
	{
		string Guess = GetGuess();
		// print the guess back
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() 
{
	//get a guess from the user
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}


