#include <stdio.h>
#include <unistd.h>

void spinner(){

    char spr[4]={"abcd"};
    int i =0;
    while(i<10){
        printf("%c\r\n", spr[i]);
        usleep(99999);
        i++;
        if (i == 5)
            i = 0;
        printf("\r\r");
    }
}


int main()
{
    printf("Hello World!\n");
    spinner();
    return 0;
}
