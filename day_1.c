#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int parsing_part_1(FILE *file)
{
    int max=0,value;
    size_t size=0;
    char *line=NULL;
    ssize_t testa=0;
    while((testa=getline(&line,&size,file))!=-1)
    {
        if(strcmp(line,"\n")==0)
        {
            if(value>max) max=value;
            value=0;
        }
        else
        {
            line[strlen(line)] = '\0';
            value+=atoi(line);
        }
    }
    return max;
}

int parsing_part_2(FILE *file)
{
    int max_1=0,max_2=0,max_3=0,value=0;
    size_t size=0;
    char *line=NULL;
    ssize_t testa=0;
    while((testa=getline(&line,&size,file))!=-1)
    {
        if(strcmp(line,"\n")==0)
        {
            if(value>=max_1) 
            {
                max_3=max_2;
                max_2=max_1;
                max_1=value;
            }
            else if(value>=max_2)
            {
                max_3=max_2;
                max_2=value;
            }
            else if(value>=max_3)
            {
                max_3=value;
            }
            value=0;
        }
        else 
        {
            line[strlen(line)] = '\0';
            value+=atoi(line);
        }
    }
    int max;
    max=max_1+max_2+max_3;
    return max;
}

int main()
{
    FILE *file=fopen("input.txt","r");
    printf("The highest value is %d.\n",parsing_part_1(file));
    rewind(file);
    printf("The sum of the 3 highests values is %d.\n",parsing_part_2(file));
}