//*******************************
// HEADER FILE FOR POWERBALLLOTTERY
//*******************************

// This is the header file for PowerballLottery, where
// we list the structure and the things that go in this class.
// This is class declaration, the implementation .cpp will be
// in another location.

#ifndef PowerballLottery_H
#define POWERBALLLOTTERY_H
//#include "PowerballTicket.h" this will not work, gives a bunch of linker errors.


using namespace std;

//************************
// CLASS DEFINITION FOR POWERBALLLOTTERY
//************************

class PowerballTicket; // this is a forward declaration. This makes sure that the compiler knows what we're doing and that we're going to be using this class
					  // this thing also took me about two hours to figure out how to implement because I kept on getting a bunch of random compiler errors
					  // whenever I tried to include a header within another one.

class PowerballLottery
{

public:

	PowerballLottery();

	PowerballLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball); // declaration of function


	// Just normally getting the ball functions. Will be generated randomly using the RandomNumber class
	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getPowerball();

	// Have to create enumeration for WinningPossibility
	enum WinningPossibility {POWERBALL, ONEPLUSPOWERBALL, TWOPLUSPOWERBALL, THREE, THREEPLUSPOWERBALL, FOUR, FOURPLUSPOWERBALL, FIVE, FIVEPLUSPOWERBALL, NOTWINNING};

	// The three things that we want to implement
	PowerballTicket quickPick();
	WinningPossibility checkTicket(PowerballTicket ticket);
	void printWhatHappened(PowerballTicket ticket);


private:
	// Private variables to be used
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mPowerball;
};

#endif // Enjoy class!