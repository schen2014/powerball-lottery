//**********************
// IMPLEMENATION FOR POWERBALLLOTTERY CLASS
//**********************

// The following code will be to define the functions that
// were listed in the PowerballLottery class that were included
// in the PowerballLottery header.

#include <iostream> // we need this for the printWhatHappened, and only for that
#include "PowerballLottery.h"
#include "PowerballTicket.h"
#include "RandomNumber.h" // need the random number generator


using namespace std;

PowerballLottery::PowerballLottery()
{
	// Need to assign a random number so let's do that using the RandomNumber header

	RandomNumber weird(1, 69); // this calls the header and assigns weird as a random number between 1 and 69
	RandomNumber strange(1, 26); // this is for the powerball

	mBall1 = weird.random();
	mBall2 = weird.random();
	mBall3 = weird.random();
	mBall4 = weird.random();
	mBall5 = weird.random();
	mPowerball = strange.random();

	// We need to ensure that there are no dupliactes among the five balls, so let's write a bunch of while functions
	// that will keep on looping until all of the balls end up being different numbers
	// This will probably end up with a lot of looping if there's ever a same number, but this will ensure that
	// There are no duplicates

	while (mBall1 == mBall2 || mBall1 == mBall3 || mBall1 == mBall4 || mBall1 == mBall5)
	{
		mBall1 = weird.random(); // just reassign it with another random number and loop until it's different from everything else
	}

	while (mBall2 == mBall3 || mBall2 == mBall4 || mBall2 == mBall5 || mBall2 == mBall1)
	{
		mBall2 = weird.random();
	}

	while (mBall3 == mBall4 || mBall3 == mBall5 || mBall3 == mBall2 || mBall3 == mBall1)
	{
		mBall3 = weird.random();
	}

	while (mBall4 == mBall5 || mBall4 == mBall3 || mBall4 == mBall2 || mBall4 == mBall1)
	{
		mBall4 = weird.random();
	}

	while (mBall5 == mBall1 || mBall5 == mBall4 || mBall5 == mBall3 || mBall5 == mBall2)
	{
		mBall5 = weird.random();
	}
}

PowerballLottery::PowerballLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball)
{
	// This is if there's a specified Powerball ticket that was input and requested

	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mPowerball = powerball;
}


// Same thing as the PowerballTicket class, we need to define the getBall (it is pretty much exactly the same
// as the previous class). However, if we don't include this, our header gets a bunch of green squiggly lines
// saying that the getBall functions are not defined.

int PowerballLottery::getBall1()
{
	return mBall1;
}

int PowerballLottery::getBall2()
{
	return mBall2;
}

int PowerballLottery::getBall3()
{
	return mBall3;
}

int PowerballLottery::getBall4()
{
	return mBall4;
}

int PowerballLottery::getBall5()
{
	return mBall5;
}

int PowerballLottery::getPowerball()
{
	return mPowerball;
}


//***********
// QUICK PICK
//***********

// So here's how we're going to tackle this function first and foremost
// We need to use the random number generator again in order to create random numbers for the five balls
// Then we have to check if the five balls are the same again.
// After we do this, then we can take all of these values and feed them into the PowerballTicket class
// This will generate a random ticket for the PowerballTicket, mimicking a "quick pick"

PowerballTicket PowerballLottery::quickPick()
{
	// we need new integers, I tried to use mBall again but I realized that it would just overwrite and that'd be bad
	// establish new integers to generate the ticket
	
	RandomNumber weird2(1, 69);
	RandomNumber strange2(1, 26);

	int ticketBall1 = 0; // arbitrary start value
	int ticketBall2 = 0;
	int ticketBall3 = 0;
	int ticketBall4 = 0;
	int ticketBall5 = 0;
	int ticketPowerball = 0;

	ticketBall1 = weird2.random();
	ticketBall2 = weird2.random();
	ticketBall3 = weird2.random();
	ticketBall4 = weird2.random();
	ticketBall5 = weird2.random();
	ticketPowerball = strange2.random();


	while (ticketBall1 == ticketBall2 || ticketBall1 == ticketBall3 || ticketBall1 == ticketBall4 || ticketBall1 == ticketBall5)
	{
		ticketBall1 = weird2.random();
	}

	while (ticketBall2 == ticketBall3 || ticketBall2 == ticketBall4 || ticketBall2 == ticketBall5 || ticketBall2 == ticketBall1)
	{
		ticketBall2 = weird2.random();
	}

	while (ticketBall3 == ticketBall4 || ticketBall3 == ticketBall5 || ticketBall3 == ticketBall2 || ticketBall3 == ticketBall1)
	{
		ticketBall3 = weird2.random();
	}

	while (ticketBall4 == ticketBall5 || ticketBall4 == ticketBall3 || ticketBall4 == ticketBall2 || ticketBall4 == ticketBall1)
	{
		ticketBall4 = weird2.random();
	}

	while (ticketBall5 == ticketBall1 || ticketBall5 == ticketBall4 || ticketBall5 == ticketBall3 || ticketBall5 == ticketBall2)
	{
		ticketBall5 = weird2.random();
	}

	return PowerballTicket(ticketBall1, ticketBall2, ticketBall3, ticketBall4, ticketBall5, ticketPowerball); // feed this into PowerballTicket in order to create a ticket
}


//*********************
// CHECK TICKET
//*********************

// So we're going to have to put these values into arrays so that we can search through them because
// as of now they're kind of just embedded into the functions. In order to get these values out, we need to use
// the function getBall that we defined. I should have realized this before I spent a good 30 minutes trying to
// figure out how to extract each individual value from the class output and input them into an array.

PowerballLottery::WinningPossibility PowerballLottery::checkTicket(PowerballTicket ticket)
{
	// putting the values of ticket and the winning combination into arrays so that we can search through them more easily
	int array1[] = { ticket.getBall1(), ticket.getBall2(), ticket.getBall3(), ticket.getBall4(), ticket.getBall5(), ticket.getPowerball() };
	int array2[] = { mBall1, mBall2, mBall3, mBall4, mBall5, mPowerball };

	int i = 0;
	int matches = 0;

	// Loook through each element and see if there are matches. We don't want duplicates so I'm going to use a while loop
	// Keep the array2 fixed while the array1 counter gets incremented up to 5.
	// I prefer not to use for loops here because then we have to take into account any duplicate values. These while loops make
	// everything a lot cleaner, although under normal circumstances I would write a nested for loop to search this.

	while (i < 5) // we only want to go until 5 because we don't care if any of these values match with the powerball since they're a seprate entity.
	{
		if (array2[0] == array1[i])
		{
			matches++;
		}
		i++;
	}

	i = 0; // forgot to reset it each time

	while (i < 5)
	{
		if (array2[1] == array1[i])
		{
			matches++;
		}
		i++;
	}

	i = 0;

	while (i < 5)
	{
		if (array2[2] == array1[i])
		{
			matches++;
		}
		i++;
	}

	i = 0;

	while (i < 5)
	{
		if (array2[3] == array1[i])
		{
			matches++;
		}
		i++;
	}

	i = 0;

	while (i < 5)
	{
		if (array2[4] == array1[i])
		{
			matches++;
		}
		i++;
	}

	i = 0;

	// Here now we have to use an if statement tree and see if anything has been matched.
	// It is very convenient here that we know the permanent size of the array (since both arrays
	// will have 6 values), unlike Project 4 where we had to deal with an unknown array size
	// and risked falling off the edge of the array.
	// Here, however, we know that the powerball corresponds with the last value, array[5].

	if (array1[5] == array2[5] && matches == 0) // almost forgot matches == 0 so I kept on getting POWERBALL winners
	{
		return POWERBALL;
	}

	else if (matches == 1 && array1[5] == array2[5])
	{
		return ONEPLUSPOWERBALL;
	}

	else if (matches == 2 && array1[5] == array2[5])
	{
		return TWOPLUSPOWERBALL;
	}

	else if (matches == 3 && array1[5] != array2[5])
	{
		return THREE;
	}

	else if (matches == 3 && array1[5] == array2[5])
	{
		return THREEPLUSPOWERBALL;
	}

	else if (matches == 4 && array1[5] != array2[5])
	{
		return FOUR;
	}

	else if (matches == 4 && array1[5] == array2[5])
	{
		return FOURPLUSPOWERBALL;
	}

	else if (matches == 5 && array1[5] != array2[5])
	{
		return FIVE;
	}
	else if (matches == 5 && array1[5] == array2[5]) // JACKPOT!
	{
		return FIVEPLUSPOWERBALL;
	}
	else
	{
		return NOTWINNING; // You win some, you lose some.
	}
}


//*********************
// PRINT WHAT HAPPENED
//*********************

// This is a relatively easy function, it's basically a large if statement tree that calls the
// checkTicket function that we just wrote above and looks at the return outputs of the function.
// In fact, this function is basically an extension of the previous one, just with cout.


void PowerballLottery::printWhatHappened(PowerballTicket ticket)
{
	if (checkTicket(ticket) == NOTWINNING)
	{
		cout << "You didn't win anything.  Please buy another ticket!" << endl;
	}
	else if (checkTicket(ticket) == POWERBALL)
	{
		cout << "You matched just the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == ONEPLUSPOWERBALL)
	{
		cout << "You matched one ball plus the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == TWOPLUSPOWERBALL)
	{
		cout << "You matched two balls plus the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == THREEPLUSPOWERBALL)
	{
		cout << "You matched three balls plus the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == THREE)
	{
		cout << "You matched three balls but not the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == FOURPLUSPOWERBALL)
	{
		cout << "You matched four balls plus the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == FOUR)
	{
		cout << "You matched four balls but not the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == FIVE)
	{
		cout << "You matched five balls but not the powerball.  Congratulations!" << endl;
	}
	else if (checkTicket(ticket) == FIVEPLUSPOWERBALL)
	{
		cout << "You won the jackpot - all balls plus the powerball.  Congratulations!" << endl;
	}
}