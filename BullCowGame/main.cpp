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
FText GetValidGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " <<  BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	//loop  for number of guesses
	for (int32 Count = 1; Count <= MaxTries; Count++)	//TODO change from FOR to WHILE loop
	{
		FText Guess = GetValidGuess();  
		
		//submit valid guess to the game and recieve counts
		FBullCowCount BullCowCount =  BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	//  TODO add a game summary at end
}

//loop continuously until the user gives a valid guess
FText GetValidGuess()  
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get a guess from the user
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.IsGuessValid(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please Enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Incorrect_Case:
			std::cout << "Please Enter word using only lower case.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please try again, Remember we're looking for an isogram so no repeating letters!\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);  //keep looping until valid guess
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}




