#include <stdio.h>
#include <unistd.h>

void spinner(){

    char spr[4]={"\\|/-"};
    int i =0;
    while(i<10){
        printf("%c\r", spr[i]);
        fflush(stdout);
        usleep(99999);  //can bu adjusted as you wish... I like it slow... >:)
        i++;
        if (i == 4)
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
