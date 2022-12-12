#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test(char *new)
{
    int i=0;
    int j;
    while(new[i]!='\0')
    {
        j=i+1;
        while(new[j]!='\0')
        {
            if(new[i]==new[j++]) return 0;
        }
        i++;
    }
    return 1;
}

int part(char *line,int chars)
{
    int i=0,j=0,l;
    char *new=malloc((chars+1)*sizeof(char));
    while(line[i]!='\0')
    {
        j=i;
        l=0;
        while(l<chars)
        {
            new[l++]=line[j++];
        }
        new[l]='\0';
        i++;
        if(test(new)) return j;
    }
    return 0;
}


int main()
{
    FILE *file=fopen("input.txt","r");
    char *line;
    size_t size;
    getline(&line,&size,file);
    printf("part one: %d.\n",part(line,4));
    printf("part two: %d.\n",part(line,14));
}