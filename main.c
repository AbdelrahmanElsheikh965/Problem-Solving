#include <stdio.h>
#include <stdlib.h>

size_t * getSize(char * text);
int * occur(char * str, char c);

int main()
{
    char * str  = "demopaddin";
    char c      = 'd';

    int * finalResult = occur(str, c);
    int k = *(getSize(str)) -1;

    while(k >= 0)
    {
      if(*(finalResult-k) != -2)
        printf("%d\t", *(finalResult-k));
      k--;
    }
    return 0;
}

int * occur(char * str, char c)
{
    size_t * size = getSize(str);
    int * result_pointer = (int *)malloc(sizeof(int) * (*size));
    int i = 0;
    while(*str)
    {
        if(*str == c)
        {
            *(result_pointer++) = i;
        }
        else
        {
            *(result_pointer++) = -2;
        }
        str++;
        i++;
    }

    return result_pointer-1;
}

size_t * getSize(char * text)
{
    size_t * size = malloc(sizeof(size_t));
    *size = 0;
    while(*text)
    {
        text++;
        (*size)++;
    }
    return size;
}
