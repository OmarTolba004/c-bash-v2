output : simpleShell.c
	@gcc simpleShell.c functions.c data_structures.c bash_variables.c -o output

clean:
	@rm -f output 
