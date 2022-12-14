Programa: main.c globalVariables.h
	gcc -o Programa main.c clock.c timer.c process.c scheduler.c -ggdb

clean:
	-rm $(objects) Programa