all: clean stairCase install

stairCase:
	gcc -o stairCase src/main.c src/stair.c

install:
	sudo cp stairCase /usr/local/bin

clean:
	rm -f stairCase
	sudo rm -f /usr/local/bin/stairCase