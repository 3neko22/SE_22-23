Programa: main.c include/globalVariables.h
	gcc -o Programa main.c src/clock.c src/timer.c src/process.c src/scheduler.c -ggdb

clean:
	-rm $(objects) Programa