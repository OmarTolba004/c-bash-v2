#include <stdio.h>
#define ESLAM 50

extern char **environ;
int main(int argc, char * argv[])
{
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}

#if 0
	for (int i = 0; environ[i] != NULL; i++)
	{
		printf("environ[%d]: %s\n", i, environ[i]);
	}
#endif
	getchar();
	return ESLAM;
}
