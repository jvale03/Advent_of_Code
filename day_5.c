#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack
{
    int sp;
    int size;
    char *elem;
} STACK;

char pop(STACK *stack)
{ 
    stack->sp--;
    char elem=stack->elem[stack->sp];
    return elem;    
}

void push(STACK *stack,char elem)
{
    if(stack->sp==stack->size)
    {
        stack->size*=2;
        stack->elem=realloc(stack->elem,stack->size*sizeof(char));
    }
    stack->elem[stack->sp]=elem;
    stack->sp++;
}

void part_1(FILE *file,STACK **s)
{
    char *line=NULL;
    size_t size=0;
    ssize_t test=0;
    int mv,from,to;
    char elem;
    while((test=getline(&line,&size,file))!=-1)
    {
        int i=0;
        mv=atoi(strtok(line,"move"));
        from=atoi(strtok(NULL,"from"));
        to=atoi(strtok(NULL,"to"));
        while(i<mv && i<s[from]->sp)
        {
            elem=pop(s[from]);
            push(s[to],elem);
            i++;
        }
    }
}


int main()
{
    FILE *file = fopen("input.txt","r");
    STACK **arr_stacks=malloc(10*sizeof(struct stack));
    /*
    1
    */
    arr_stacks[1]=malloc(sizeof(struct stack));
    arr_stacks[1]->sp=3;
    arr_stacks[1]->size=4;
    arr_stacks[1]->elem[0]='W';
    arr_stacks[1]->elem[1]='R';
    arr_stacks[1]->elem[2]='F';
    /*
    2
    */
    arr_stacks[2]=malloc(sizeof(struct stack));
    arr_stacks[2]->sp=8;
    arr_stacks[2]->size=8;
    arr_stacks[2]->elem[0]='T';
    arr_stacks[2]->elem[1]='H';
    arr_stacks[2]->elem[2]='M';
    arr_stacks[2]->elem[3]='C';
    arr_stacks[2]->elem[4]='D';
    arr_stacks[2]->elem[5]='V';
    arr_stacks[2]->elem[6]='W';
    arr_stacks[2]->elem[7]='P';
    /*
    3
    */
    arr_stacks[3]=malloc(sizeof(struct stack));
    arr_stacks[3]->sp=5;
    arr_stacks[3]->size=8;
    arr_stacks[3]->elem[0]='P';
    arr_stacks[3]->elem[1]='M';
    arr_stacks[3]->elem[2]='Z';
    arr_stacks[3]->elem[3]='N';
    arr_stacks[3]->elem[4]='L';
    /*
    3
    */
    arr_stacks[4]=malloc(sizeof(struct stack));
    arr_stacks[4]->sp=4;
    arr_stacks[4]->size=4;
    arr_stacks[4]->elem[0]='J';
    arr_stacks[4]->elem[1]='C';
    arr_stacks[4]->elem[2]='H';
    arr_stacks[4]->elem[3]='R';
    /*
    3
    */
    arr_stacks[5]=malloc(sizeof(struct stack));
    arr_stacks[5]->sp=7;
    arr_stacks[5]->size=8;
    arr_stacks[5]->elem[0]='C';
    arr_stacks[5]->elem[1]='P';
    arr_stacks[5]->elem[2]='G';
    arr_stacks[5]->elem[3]='H';
    arr_stacks[5]->elem[4]='Q';
    arr_stacks[5]->elem[5]='T';
    arr_stacks[5]->elem[6]='B';
    /*
    2
    */
    arr_stacks[6]=malloc(sizeof(struct stack));
    arr_stacks[6]->sp=6;
    arr_stacks[6]->size=8;
    arr_stacks[6]->elem[0]='G';
    arr_stacks[6]->elem[1]='C';
    arr_stacks[6]->elem[2]='W';
    arr_stacks[6]->elem[3]='L';
    arr_stacks[6]->elem[4]='F';
    arr_stacks[6]->elem[5]='Z';
    /*
    2
    */
    arr_stacks[7]=malloc(sizeof(struct stack));
    arr_stacks[7]->sp=8;
    arr_stacks[7]->size=8;
    arr_stacks[7]->elem[0]='W';
    arr_stacks[7]->elem[1]='V';
    arr_stacks[7]->elem[2]='L';
    arr_stacks[7]->elem[3]='Q';
    arr_stacks[7]->elem[4]='Z';
    arr_stacks[7]->elem[5]='J';
    arr_stacks[7]->elem[6]='G';
    arr_stacks[7]->elem[7]='C';
    /*
    2
    */
    arr_stacks[8]=malloc(sizeof(struct stack));
    arr_stacks[8]->sp=8;
    arr_stacks[8]->size=8;
    arr_stacks[8]->elem[0]='P';
    arr_stacks[8]->elem[1]='N';
    arr_stacks[8]->elem[2]='R';
    arr_stacks[8]->elem[3]='F';
    arr_stacks[8]->elem[4]='W';
    arr_stacks[8]->elem[5]='T';
    arr_stacks[8]->elem[6]='V';
    arr_stacks[8]->elem[7]='C';
    /*
    2
    */
    arr_stacks[9]=malloc(sizeof(struct stack));
    arr_stacks[9]->sp=7;
    arr_stacks[9]->size=8;
    arr_stacks[9]->elem[0]='J';
    arr_stacks[9]->elem[1]='W';
    arr_stacks[9]->elem[2]='H';
    arr_stacks[9]->elem[3]='G';
    arr_stacks[9]->elem[4]='R';
    arr_stacks[9]->elem[5]='S';
    arr_stacks[9]->elem[6]='V';
    part_1(file,arr_stacks);
    printf("1 -> %c \n2 -> %c \n3 -> %c \n4 -> %c \n5 -> %c \n6 -> %c \n7 -> %c \n 8 -> %c \n9 -> %c \n",arr_stacks[1]->elem[arr_stacks[1]->sp],arr_stacks[2]->elem[arr_stacks[2]->sp],arr_stacks[3]->elem[arr_stacks[3]->sp],arr_stacks[4]->elem[arr_stacks[4]->sp],arr_stacks[5]->elem[arr_stacks[5]->sp],arr_stacks[6]->elem[arr_stacks[6]->sp],arr_stacks[7]->elem[arr_stacks[7]->sp],arr_stacks[8]->elem[arr_stacks[8]->sp],arr_stacks[9]->elem[arr_stacks[9]->sp]);
}