output : simpleShell.c
	@gcc simpleShell.c functions.c -o output

clean:
	@rm -f output 
