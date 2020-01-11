CPP=g++ --std=c++11 -Wall

all : Game

Game : main.o Board.o Combat.o FonctionUtile.o GameMap.o Jeu.o Entity.o Oueurj.o Pos.o Monster_o.o Monster_s.o Streumon.o TextOutput.o
	$(CPP) -o Game main.o Board.o Combat.o FonctionUtile.o GameMap.o Jeu.o Entity.o Oueurj.o Pos.o Monster_o.o Monster_s.o Streumon.o TextOutput.o

main.o : main.cpp
	$(CPP) -o main.o -c main.cpp

Board.o : Board.cpp
	$(CPP) -o Board.o -c Board.cpp

Combat.o : Combat.cpp
	$(CPP) -o Combat.o -c Combat.cpp

FonctionUtile.o : FonctionUtile.cpp
	$(CPP) -o FonctionUtile.o -c FonctionUtile.cpp

GameMap.o : GameMap.cpp
	$(CPP) -o GameMap.o  -c GameMap.cpp

Jeu.o : Jeu.cpp
	$(CPP) -o Jeu.o  -c Jeu.cpp

Entity.o : Entities/Entity.cpp
	$(CPP) -o Entity.o  -c Entities/Entity.cpp

Oueurj.o : Entities/Oueurj.cpp
	$(CPP) -o Oueurj.o  -c Entities/Oueurj.cpp

Pos.o : Entities/Pos.cpp
	$(CPP) -o Pos.o  -c Entities/Pos.cpp

Monster_o.o : Entities/Streumons/Monster_o.o
	$(CPP) -o Monster_o.o  -c Entities/Streumons/Monster_o.cpp

Monster_s.o : Entities/Streumons/Monster_s.o
	$(CPP) -o Monster_s.o  -c Entities/Streumons/Monster_s.cpp

Streumon.o : Entities/Streumons/Streumon.o
	$(CPP) -o Streumon.o  -c Entities/Streumons/Streumon.cpp

TextOutput.o : TextOutput.cpp
	$(CPP) -o TextOutput.o -c TextOutput.cpp

clean :
	rm *.o
