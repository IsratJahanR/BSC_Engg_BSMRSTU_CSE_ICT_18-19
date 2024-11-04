/* Coding Assignment 6 */
/* Name: Nadia Thonu */
/* id: 1001983393 */

#include <stdio.h>
#define HASHTABLESIZE 10

typedef struct Phone
{
    char *Name;
    float height; //in
    float width;  //in
    char Face_ID;
    int weight;   //g
    struct Phone *next_ptr;
}
PHONE;

int MyHashFunction(char *str) //iphone 6
{
    //perform hash method
    int value=0;
    for(int i = 0; i<strlen(str); i++)
    {
        value += str[i];
    }
    return value % HASHTABLESIZE;
}

int main(void)
{
    char HashValue[20];
    printf("Enter value ");
    fgets(HashValue,sizeof(HashValue)-1, stdin);
    printf("The hash value for %s is %d\n", HashValue, MyHashFunction(HashValue));
    return 0;
}
