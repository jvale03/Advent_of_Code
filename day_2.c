#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define X 1
#define Y 2
#define Z 3

int part_1(FILE *file)
{
    int points=0;
    size_t size=0;
    ssize_t test=0;
    char *line=NULL;
    while((test=getline(&line,&size,file))!=-1)
    {
        char *token_elf=strtok(line," ");
        char *token_me=strtok(NULL," ");
        token_elf[1] = '\0';
        token_me[1] = '\0';
        if(strcmp(token_elf,"A")==0) token_elf="X";  
        else if(strcmp(token_elf,"B")==0) token_elf="Y";  
        else if(strcmp(token_elf,"C")==0) token_elf="Z";  
        if(strcmp(token_elf,token_me)==0)
        {
            points+=3;
            if(strcmp(token_me,"X")==0) points+=X;
            else if(strcmp(token_me,"Y")==0) points+=Y;
            else if(strcmp(token_me,"Z")==0) points+=Z;
        }
        else if((strcmp(token_elf,"X")==0 && strcmp(token_me,"Y")==0) || (strcmp(token_elf,"Y")==0 && strcmp(token_me,"Z")==0) || (strcmp(token_elf,"Z")==0 && strcmp(token_me,"X")==0))
        {
            points+=6;
            if(strcmp(token_me,"X")==0) points+=X;
            else if(strcmp(token_me,"Y")==0) points+=Y;
            else if(strcmp(token_me,"Z")==0) points+=Z;
        }
        else
        {
            if(strcmp(token_me,"X")==0) points+=X;
            else if(strcmp(token_me,"Y")==0) points+=Y;
            else if(strcmp(token_me,"Z")==0) points+=Z;
        }
    }
    return points;
}

int part_2(FILE *file)
{
    int points=0;
    size_t size=0;
    ssize_t test=0;
    char *line=NULL;
    while((test=getline(&line,&size,file))!=-1)
    {
        char *token_elf=strtok(line," ");
        char *token_me=strtok(NULL," ");
        token_elf[1] = '\0';
        token_me[1] = '\0';
        if(strcmp(token_me,"Y")==0) //draw
        {
            points+=3;
            if(strcmp(token_elf,"A")==0) points+=1;
            else if(strcmp(token_elf,"B")==0) points+=2;
            else if(strcmp(token_elf,"C")==0) points+=3;
        }
        else if(strcmp(token_me,"X")==0) //lose
        {
            if(strcmp(token_elf,"A")==0) points+=3;
            else if(strcmp(token_elf,"B")==0) points+=1;
            else if(strcmp(token_elf,"C")==0) points+=2;
        }
        else if(strcmp(token_me,"Z")==0) //win
        {
            points+=6;
            if(strcmp(token_elf,"A")==0) points+=2;
            else if(strcmp(token_elf,"B")==0) points+=3;
            else if(strcmp(token_elf,"C")==0) points+=1;
        }
    }
    return points;
}

int main()
{
    FILE *file=fopen(".gitignore/input.txt","r");
    printf("Total %d.\n",part_1(file));
    rewind(file);
    printf("Total %d.\n",part_2(file));
}