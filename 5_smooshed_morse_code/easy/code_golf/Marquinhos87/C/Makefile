all: clean morseCode install

morseCode:
	gcc -o morseCode src/main.c src/morse.c

install:
	sudo cp morseCode /usr/local/bin

clean:
	rm -f morseCode
	sudo rm -f /usr/local/bin/morseCode