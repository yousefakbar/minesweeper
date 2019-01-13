mine_sweeper.out: win.o move.o board.o main.o
	gcc -g -Wall -Werror -o mine_sweeper.out win.o move.o board.o main.o

win.o: win.c win.h structs.h
	gcc -g -Wall -Werror -c win.c

move.o: move.c move.h structs.h board.h
	gcc -g -Wall -Werror -c move.c

board.o: board.c board.h structs.h
	gcc -g -Wall -Werror -c board.c

main.o: main.c move.h board.h win.h structs.h
	gcc -g -Wall -Werror -c main.c

clean:
	rm -fr *.o *.out