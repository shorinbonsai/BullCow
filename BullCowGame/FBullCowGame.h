#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon(std::string) const;

	void Reset();  // TODO make a more rich return value
	bool IsGuessValid(std::string);  // TODO make a more rich return value

private:
	//see constructor for initialisations
	int MyCurrentTry;
	int MyMaxTries;

};