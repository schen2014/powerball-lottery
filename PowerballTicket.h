//***********************************
// Establishing the header file for PowerballTicket
//***********************************

// Note to self that this will be a simple writing of the class structure
// The implementation of all of these functions will be in the implementation file
// Which will be the .cpp that will be related to this file.

#ifndef PowerballTicket_H // Declares class
#define POWERBALL_H

using namespace std;

//****************************
// CLASS DEFINITION FOR POWERBALLTICKET
//****************************


class PowerballTicket
{

public:
	PowerballTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball); // declaration of the function

	// Public declarations of getBalls

	int getBall1(); 
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getPowerball();

private:

	// Private variables that will only be used for the implementation .cpp

	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mPowerball;
};

#endif // can't forget this!