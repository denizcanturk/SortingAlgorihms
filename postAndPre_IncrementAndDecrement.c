/*
 * AUTHOR   : Anonymous
 * Narrator : Deniz CANTÜRK
 * This snippet gives the oversight
 * on usage of POST and PRE _
 * increments and decrements and
 * their affects on the variables...
*/

#include <stdio.h>

int main()
{
    // Post increment
    printf("<=== Post-increment (x++) ===>\n");
    int a = 1;
    printf("b = a++\n");
    printf("a value: %d, b value : 0\n",a);
    int b = a++;
    printf("b value after a++ : %d\n", b);
    printf("a value after a++ : %d\n", a);
    printf("\n");
    // Pre increment
    printf("<=== Pre-increment (++x) ===>\n");
    a = 1;
    printf("b = ++a\n");
    printf("a value : %d, b value : 0\n", a);
    b = ++a;
    printf("b value after ++a : %d\n", b);
    printf("a value after ++a : %d\n", a);
    printf("\n");
    // Post decrement
    printf("<=== Post-increment (x--) ===>\n");
    a = 5;
    printf("b = a--\n");
    printf("a value: %d, b value : 0\n",a);
    printf("a value before decrement : %d\n", a);
    b = a--;
    printf("b value after a-- : %d\n", b);
    printf("a value after a-- : %d\n", a);
    printf("\n");
    // Pre decrement
    printf("<=== Pre-increment (--x) ===>\n");
    a = 5;
    printf("b = --a\n");
    printf("a value: %d, b value : 0\n",a);
    b = --a;
    printf("b value after --a : %d\n", b);
    printf("a value after --a : %d\n", a);
    return 0;
}
