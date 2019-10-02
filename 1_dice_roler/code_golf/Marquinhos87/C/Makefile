all: clean diceRoler install

diceRoler:
	gcc -o diceRoler src/main.c src/diceroler.c

install:
	sudo cp diceRoler /usr/local/bin

clean:
	rm -f /usr/local/bin/diceRoler
