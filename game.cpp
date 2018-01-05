//***************************
// GAME.CPP
//***************************

// This is the main testing file for all of the classes and things that we are implementing

#include <iostream>
#include <string>
#include <cassert>
#include "PowerballTicket.h"
#include "PowerballLottery.h"



int main()
{
	//test code
	PowerballTicket ticket(1, 2, 3, 4, 5, 6);
	assert(ticket.getBall1() == 1);
	assert(ticket.getBall2() == 2);
	assert(ticket.getBall3() == 3);
	assert(ticket.getBall4() == 4);
	assert(ticket.getBall5() == 5);
	assert(ticket.getPowerball() == 6);

	PowerballTicket chance(1, 45, 27, 9, 32, 22);
	assert(chance.getBall1() == 1);
	assert(chance.getBall2() == 45);
	assert(chance.getBall3() == 27);
	assert(chance.getBall4() == 9);
	assert(chance.getBall5() == 32);
	assert(chance.getPowerball() == 22);



	PowerballLottery lottery(1, 2, 3, 4, 5, 6);
	assert(lottery.getBall1() == 1);
	assert(lottery.getBall2() == 2);
	assert(lottery.getBall3() == 3);
	assert(lottery.getBall4() == 4);
	assert(lottery.getBall5() == 5);
	assert(lottery.getPowerball() == 6);

	PowerballTicket ticket2(2, 3, 4, 5, 6, 7);
	PowerballLottery lottery2(2, 3, 4, 5, 6, 8);
	assert(lottery.checkTicket(ticket) == 8);
	assert(lottery2.checkTicket(ticket2) == 7);
	assert(lottery.checkTicket(chance) == 9);

	//lottery.printWhatHappened(ticket);

	PowerballTicket tick1(1, 2, 3, 4, 5, 6);
	PowerballLottery lott1(6, 7, 8, 9, 10, 6);
	assert(lott1.checkTicket(tick1) == 0);
	lott1.printWhatHappened(tick1);

	PowerballTicket tick2(4, 5, 6, 7, 8, 10);
	PowerballLottery lott2(11, 12, 13, 14, 4, 10);
	assert(lott2.checkTicket(tick2) == 1);
	lott2.printWhatHappened(tick2);

	PowerballTicket tick3(4, 5, 6, 7, 8, 11);
	PowerballLottery lott3(6, 7, 11, 12, 13, 11); // This will check if the order of numbers doesn't matter
	assert(lott3.checkTicket(tick3) == 2);
	lott3.printWhatHappened(tick3);

	PowerballTicket tick4(1, 2, 3, 9, 10, 14);
	PowerballLottery lott4(1, 2, 3, 4, 5, 7);
	assert(lott4.checkTicket(tick4) == 3);
	lott4.printWhatHappened(tick4);

	PowerballTicket tick5(1, 2, 3, 9, 10, 7);
	PowerballLottery lott5(1, 2, 4, 3, 5, 7);
	assert(lott5.checkTicket(tick5) == 4);
	lott5.printWhatHappened(tick5);

	PowerballTicket tick6(1, 2, 3, 4, 9, 10);
	PowerballLottery lott6(1, 2, 3, 4, 5, 6);
	assert(lott6.checkTicket(tick6) == 5);
	lott6.printWhatHappened(tick6);

	PowerballTicket tick7(1, 2, 3, 4, 9, 6);
	PowerballLottery lott7(1, 2, 3, 4, 5, 6);
	assert(lott7.checkTicket(tick7) == 6);
	lott7.printWhatHappened(tick7);

	PowerballTicket tick8(21, 22, 23, 24, 25, 26);
	PowerballLottery lott8(21, 22, 23, 24, 25, 27);
	assert(lott8.checkTicket(tick8) == 7);
	lott8.printWhatHappened(tick8);

	PowerballTicket tick9(31, 32, 33, 34, 35, 36);
	PowerballLottery lott9(31, 32, 33, 34, 35, 36);
	assert(lott9.checkTicket(tick9) == 8);
	lott9.printWhatHappened(tick9);

	PowerballTicket tick10(4, 56, 34, 50, 28, 4);
	PowerballLottery lott10(5, 49, 10, 23, 60, 9);
	assert(lott10.checkTicket(tick10) == 9);
	lott10.printWhatHappened(tick10);

	// For fun, let's simulate an actual Lottery!
	PowerballLottery test(1, 2, 3, 4, 5, 6);
	PowerballLottery actuallott = PowerballLottery(); // calling a random one!
	PowerballTicket quickPickTick(5, 27, 42, 31, 18, 5); // my lucky numbers
	actuallott.printWhatHappened(quickPickTick);
	// I'm so unlucky...I haven't won anything, not even the Powerball

	PowerballLottery test2(1, 2, 3, 4, 5, 6);
	PowerballTicket quickPickTick2(1, 2, 3, 4, 5, 6);
	quickPickTick2 = test2.quickPick();
	actuallott.printWhatHappened(quickPickTick2);


	PowerballTicket quickPickTicket(1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 20; i++)
	{
		quickPickTicket = lottery.quickPick();
		// all the ball numbers need to be different...
		assert(quickPickTicket.getBall1() != quickPickTicket.getBall2() &&
			quickPickTicket.getBall1() != quickPickTicket.getBall3() &&
			quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
			quickPickTicket.getBall1() != quickPickTicket.getBall5() &&
			quickPickTicket.getBall2() != quickPickTicket.getBall3() &&
			quickPickTicket.getBall2() != quickPickTicket.getBall4() &&
			quickPickTicket.getBall2() != quickPickTicket.getBall5() &&
			quickPickTicket.getBall3() != quickPickTicket.getBall4() &&
			quickPickTicket.getBall3() != quickPickTicket.getBall5() &&
			quickPickTicket.getBall4() != quickPickTicket.getBall5());
	}

	

	cout << "All tests succeeded!" << endl;
}