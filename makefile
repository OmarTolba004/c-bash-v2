output : simpleShell.c functions.c data_structures.c bash_variables.c
	@gcc simpleShell.c functions.c data_structures.c bash_variables.c -o output



indent : 
	@indent -kr *.c *.h
	@rm -f *.c~ *.h~
clean:
	@rm -f output 
