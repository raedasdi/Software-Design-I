# Go Fish!
EE312 Go Fish Project by Raed Asdi and Syed Usmani

This program implements the card, deck, and player classes in a Go Fish game with two players.
They do not use any strategy and pretty much just choose a random card in their hand to ask for.
The game has built in animations that can either be turned off or turned on to make the game
watchable to the human eye.

Compiling Instructions

Before compiling, make sure you type in the command

	module load gcc

to update the gcc compiler and allow for c++11

then just type in the command 
	
	make -f makefile

once compiled it will create an executable called test, to execute merely type

	./test

and the game will start
	
