#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon(FString) const;

	void Reset();  // TODO make a more rich return value
	bool IsGuessValid(FString);  // TODO make a more rich return value

	FBullCowCount SubmitGuess(FString);


private:
	//see constructor for initialisations
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};