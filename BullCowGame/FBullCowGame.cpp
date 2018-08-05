#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {	Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	return;
}


bool FBullCowGame::IsGameWon(std::string) const
{
	return false;
}

bool FBullCowGame::IsGuessValid(std::string)
{
	return false;
}

