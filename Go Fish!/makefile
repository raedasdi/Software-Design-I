
final: go_fish.o player.o deck.o card.o
	module load gcc
	g++ -o test go_fish.o player.o deck.o card.o
go_fish.o: go_fish.cpp player.h deck.h card.h
	module load gcc
	g++ -c -std=c++11 go_fish.cpp
player.o: player.cpp player.h
	module load gcc
	g++ -c -std=c++11 player.cpp
deck.o: deck.cpp deck.h
	module load gcc
	g++ -c -std=c++11 deck.cpp
card.o: card.cpp card.h
	module load gcc
	g++ -c -std=c++11 card.cpp