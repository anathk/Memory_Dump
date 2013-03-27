//dump.c
//CPS 536 Assignment 1 for Zhengchao Tian.
//This program provides a readable "dump" of computer 
//memory in a readable, hexadecimal format.
#include <stdio.h>

//dump function
void dump(void *p, int count, int width);

//Global variable str.
char *str = "0123456789";

//Main program may take 4 parameters:
//argv[1]: The address from which the memory dump should start.
//argv[2]: The number of bytes of memory that should be displayed.
//argv[3]: The number of bytes that should be displayed per line.
int main(int argc, char *argv[]) {
    //If the program has been invoked with 1 arguments.
    //Output the addresses of main, dump and str.
    if(argc == 1)
    {
        printf("Address of main is %016x\n", &main);
        printf("Address of dump is %016x\n", &dump);
        printf("Address of str is  %016x\n", &str);
      
        return 0;
    }
    
    //Verify the number of arguments and output error message.
    if(argc != 4)
    {
        printf("Error! This program takes 1 or 4 arguments");
        
        return -1;
    }

    void *p;
    //Converte a pointer to a string into a pointer.
    sscanf(argv[1], "%p ", &p);
    
    //Call the dump function. 
    dump(p, atoi(argv[2]), atoi(argv[3]));
    return 0;
}


void dump(void *p, int count, int width) {
    int i, j;
    //Number of rows.
    int rowNum;

    //Convert pointer type.
    unsigned char *ptr = (unsigned char *)p;
    printf("----BEGIN----\n");

    //Calculate the number of rows.
    if(count%width == 0)
	rowNum = count/width;
    else
	rowNum = count/width + 1;

    //i controls number of rows.
    for(i = 0; i < rowNum; i++)
    {
	printf("%016x ", p + width*i);
	//j controls number of items in each row.
	for(j = 0; j < width && i*width + j < count; j++)
	{
	    printf("%02x ", (unsigned char *)ptr[i*width + j]);
	}
	printf("\n");
    }
    printf("----END----\n");

    return;
}


