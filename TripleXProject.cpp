#include <iostream>
#include <ctime>

void PrintIntroduction()
{
	//Prints text to setup game story.
	std::cout << "\n\n*** You are wandering the ancient Egyptian desert\n";
	std::cout << "Eventually you run into a Sphinx, the Sphinx sais:\n";
	std::cout << "Greetings adventurer."; 
}

bool PlayGame(int Difficulty)
{
	std::cout << " A level " << Difficulty << " riddle i have for you, solve this riddle and pass, fail and you shall meet your end. ***\n\n";

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print CodeSum and CodeProduct to the terminal.
	std::cout << std::endl;
	std::cout << "* 3 Numbers are present\n";
	std::cout << "* The numbers add up to: " << CodeSum << "\n";
	std::cout << "* The numbers multiple to give: " << CodeProduct << "\n";

	// Store player guess.
	std::cout << "Guess the numbers: ";
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//Check if the players guess is correct.
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n*** You have passed this riddle\n Now i shall give you another one ***";
		return true;
	}
	else
	{
		std::cout << "\n*** WRONG! ***\n*** The Sphinx lunges at you and kills you where you stand ***";
		Difficulty = 1;
		return false;
	}
}

int main()
{
	srand(time(NULL)); // create new random sequence based on time of day.
	PrintIntroduction();

	int LevelDifficulty = 1;
	const int MaxLevel = 5;

	while (LevelDifficulty <= MaxLevel) // Loop game until last level is completed.
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clears any errors.
		std::cin.ignore(); // Discards the buffer.

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	std::cout << "\nYou have passed all of my riddles, you may go on with your journey adventurer";
	return 0;
}
