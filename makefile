output : simpleShell.c functions.c data_structures.c bash_variables.c IORedirection.c
	@gcc -g simpleShell.c functions.c data_structures.c bash_variables.c IORedirection.c -o output



indent : 
	@indent -kr *.c *.h
	@rm -f *.c~ *.h~
clean:
	@rm -f output 
