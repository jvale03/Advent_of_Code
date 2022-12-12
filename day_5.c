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

char pop_reverse(STACK *s,int i)
{
    char elem=s->elem[s->sp-i];
    return elem;
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
        while(i<mv)
        {
            elem=pop(s[from]);
            push(s[to],elem);
            i++;
        }
    }
}

void part_2(FILE *file,STACK **s)
{
    char *line=NULL;
    size_t size=0;
    ssize_t test=0;
    int mv,from,to;
    char elem;
    while((test=getline(&line,&size,file))!=-1)
    {
        mv=atoi(strtok(line,"move"));
        from=atoi(strtok(NULL,"from"));
        to=atoi(strtok(NULL,"to"));
        int i=mv;
        while(i>0)
        {
            elem=pop_reverse(s[from],i);
            push(s[to],elem);
            i--;
        }
        s[from]->sp-=mv;
    }
}


int main()
{
    FILE *file = fopen("input.txt","r");
    STACK **arr_stacks=malloc(12*sizeof(struct stack));
    arr_stacks[0]=malloc(sizeof(struct stack));
    /*
    1
    */
    arr_stacks[1]=malloc(sizeof(struct stack));
    arr_stacks[1]->sp=0;
    arr_stacks[1]->size=4;
    arr_stacks[1]->elem=malloc(arr_stacks[1]->size*sizeof(char));
    push(arr_stacks[1],'W');
    push(arr_stacks[1],'R');
    push(arr_stacks[1],'F');
    
    
    arr_stacks[2]=malloc(sizeof(struct stack));
    arr_stacks[2]->sp=0;
    arr_stacks[2]->size=4;
    arr_stacks[2]->elem=malloc(arr_stacks[2]->size*sizeof(char));
    push(arr_stacks[2],'T');
    push(arr_stacks[2],'H');
    push(arr_stacks[2],'M');
    push(arr_stacks[2],'C');
    push(arr_stacks[2],'D');
    push(arr_stacks[2],'V');
    push(arr_stacks[2],'W');
    push(arr_stacks[2],'P');
    

    arr_stacks[3]=malloc(sizeof(struct stack));
    arr_stacks[3]->sp=0;
    arr_stacks[3]->size=4;
    arr_stacks[3]->elem=malloc(arr_stacks[3]->size*sizeof(char));
    push(arr_stacks[3],'P');
    push(arr_stacks[3],'M');
    push(arr_stacks[3],'Z');
    push(arr_stacks[3],'N');
    push(arr_stacks[3],'L');

    arr_stacks[4]=malloc(sizeof(struct stack));
    arr_stacks[4]->sp=0;
    arr_stacks[4]->size=4;
    arr_stacks[4]->elem=malloc(arr_stacks[4]->size*sizeof(char));
    push(arr_stacks[4],'J');
    push(arr_stacks[4],'C');
    push(arr_stacks[4],'H');
    push(arr_stacks[4],'R');
   

    arr_stacks[5]=malloc(sizeof(struct stack));
    arr_stacks[5]->sp=0;
    arr_stacks[5]->size=4;
    arr_stacks[5]->elem=malloc(arr_stacks[5]->size*sizeof(char));
    push(arr_stacks[5],'C');
    push(arr_stacks[5],'P');
    push(arr_stacks[5],'G');
    push(arr_stacks[5],'H');
    push(arr_stacks[5],'Q');
    push(arr_stacks[5],'T');
    push(arr_stacks[5],'B');
    

    arr_stacks[6]=malloc(sizeof(struct stack));
    arr_stacks[6]->sp=0;
    arr_stacks[6]->size=4;
    arr_stacks[6]->elem=malloc(arr_stacks[6]->size*sizeof(char));
    push(arr_stacks[6],'G');
    push(arr_stacks[6],'C');
    push(arr_stacks[6],'W');
    push(arr_stacks[6],'L');
    push(arr_stacks[6],'F');
    push(arr_stacks[6],'Z');


    arr_stacks[7]=malloc(sizeof(struct stack));
    arr_stacks[7]->sp=0;
    arr_stacks[7]->size=4;
    arr_stacks[7]->elem=malloc(arr_stacks[7]->size*sizeof(char));
    push(arr_stacks[7],'W');
    push(arr_stacks[7],'V');
    push(arr_stacks[7],'L');
    push(arr_stacks[7],'Q');
    push(arr_stacks[7],'Z');
    push(arr_stacks[7],'J');
    push(arr_stacks[7],'G');
    push(arr_stacks[7],'C');


    arr_stacks[8]=malloc(sizeof(struct stack));
    arr_stacks[8]->sp=0;
    arr_stacks[8]->size=4;
    arr_stacks[8]->elem=malloc(arr_stacks[8]->size*sizeof(char));
    push(arr_stacks[8],'P');
    push(arr_stacks[8],'N');
    push(arr_stacks[8],'R');
    push(arr_stacks[8],'F');
    push(arr_stacks[8],'W');
    push(arr_stacks[8],'T');
    push(arr_stacks[8],'V');
    push(arr_stacks[8],'C');


    arr_stacks[9]=malloc(sizeof(struct stack));
    arr_stacks[9]->sp=0;
    arr_stacks[9]->size=4;
    arr_stacks[9]->elem=malloc(arr_stacks[9]->size*sizeof(char));
    push(arr_stacks[9],'J');
    push(arr_stacks[9],'W');
    push(arr_stacks[9],'H');
    push(arr_stacks[9],'G');
    push(arr_stacks[9],'R');
    push(arr_stacks[9],'S');
    push(arr_stacks[9],'V');
    
    int part;
    printf("Choose the part you want to run: ");
    scanf("%d",&part);
    if(part==1) part_1(file,arr_stacks);
    else part_2(file,arr_stacks);
    printf("part %d: %c%c%c%c%c%c%c%c%c\n",part,arr_stacks[1]->elem[arr_stacks[1]->sp-1],arr_stacks[2]->elem[arr_stacks[2]->sp-1],arr_stacks[3]->elem[arr_stacks[3]->sp-1],arr_stacks[4]->elem[arr_stacks[4]->sp-1],arr_stacks[5]->elem[arr_stacks[5]->sp-1],arr_stacks[6]->elem[arr_stacks[6]->sp-1],arr_stacks[7]->elem[arr_stacks[7]->sp-1],arr_stacks[8]->elem[arr_stacks[8]->sp-1],arr_stacks[9]->elem[arr_stacks[9]->sp-1]);
}