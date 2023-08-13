
#include "data_structures.h"
#include "bash_variables.h"
#include "functions.h"
#include <unistd.h>
#include <stdio.h>
#include "IORedirection.h"

int main(void)
{

    IORedirection_redirecting_append(1,"/home/omar/stm/assign3/testRedirection.txt");
    printf("Checking if appending on old contet work\n");


    return 0;
}
