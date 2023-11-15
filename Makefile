all:
	gcc -Wall -Werror -o crack crack.c -lcrypt
	
clean:
	rm crack