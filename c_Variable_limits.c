/*
 * AUTHOR   : Annonymous
 * Narrator : Deniz CANTÜRK
 * This snippet gives the oversight
 * regarding variables size in memory
 * including their min and max values...
*/
#include <limits.h>
#include <float.h>
//#include <conio.h>


int main()
{
printf("\nTIP\t\tBOYUT \t\tMIN DEGERI \t\tMAX DEGERI\n");
printf("==================================================================\n");
printf("char\t\t:%lu byte(s)\t%d\t\t\t%d\n",sizeof (char), CHAR_MIN, CHAR_MAX);
printf("short\t\t:%lu byte(s)\t%d\t\t\t%d\n",sizeof (int), SHRT_MIN, SHRT_MAX);
printf("int\t\t:%lu byte(s)\t%d\t\t%d\n",sizeof (int), INT_MIN, INT_MAX);
printf("unsigned:\t:%lu byte(s)\t%d\t\t\t%d\n",sizeof (unsigned), 0, UINT_MAX);
printf("long\t\t:%lu byte(s)\t%ld\t%ld\n",sizeof (long), LONG_MIN, LONG_MAX);
printf("float\t\t:%lu byte(s)\t%f\t\t%f\n",sizeof (float), FLT_MIN, FLT_MAX);
printf("double\t\t:%lu byte(s)\t%f\t\t%f\n",sizeof (double), DBL_MIN, DBL_MAX);
getchar();
    return 0;
}
