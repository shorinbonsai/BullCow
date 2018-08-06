/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	do 
	{
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());
	return 0; //exit application
}

void PrintIntro()
{
	//introduce the game
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	//loop  for number of guesses
	//TODO change from FOR to WHILE loop once we are validating tries
	for (int32 Count = 1; Count <= MaxTries; Count++)
	{
		FText Guess = GetGuess();  // TODO make loop checking valid guesses

		//submit valid guess to the game and recieve counts
		FBullCowCount BullCowCount =  BCGame.SubmitGuess(Guess);
		//print cumber of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}
	//  TODO add a game summary at end
}

FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the user
	std::cout <<"Try " <<CurrentTry  << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}




