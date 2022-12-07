#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int part_1(FILE *file)
{
    size_t size=0;
    ssize_t test=0;
    char *line=NULL;
    int x_1,x_2,y_1,y_2,value=0;
    while((test=getline(&line,&size,file))!=-1)
    {
        x_1=atoi(strtok(line,"-"));
        x_2=atoi(strtok(NULL,","));
        y_1=atoi(strtok(NULL,"-"));
        y_2=atoi(strtok(NULL,"\n"));
        if((y_1>=x_1 && y_2<=x_2) || (y_1<=x_1 && y_2>=x_2)) value++;
    }
    return value;
}

int tests(int *x,int *y,int vx, int vy)
{
    int i=0,j=0;
    while(i<vx)
    {
        while(j<vy)
        {
            if(x[i]==y[j]) return 1;
            j++;
        }
        j=0;
        i++;
    }
    return 0;
}

void imprime(int *x,int d)
{
    int i=0;
    while(i<d)
    {
        printf("%d,",x[i++]);
    }
}

int part_2(FILE *file)
{
    size_t size=0;
    ssize_t test=0;
    char *line=NULL;
    int x_1,x_2,y_1,y_2,value=0,difference_x,difference_y;
    int *values_x=malloc(sizeof(int)),*values_y=malloc(sizeof(int));
    while((test=getline(&line,&size,file))!=-1)
    {
        int i=0;
        x_1=atoi(strtok(line,"-"));
        x_2=atoi(strtok(NULL,","));
        y_1=atoi(strtok(NULL,"-"));
        y_2=atoi(strtok(NULL,"\n"));
        difference_x=x_2-x_1+1;
        difference_y=y_2-y_1+1;
        values_x=realloc(values_x,difference_x*sizeof(int));
        values_y=realloc(values_y,difference_y*sizeof(int));
        while(i<difference_x)
        {
            values_x[i++]=x_1++;
        }
        i=0;
        while(i<difference_y)
        {
            values_y[i++]=y_1++;
        }
        if(tests(values_x,values_y,difference_x,difference_y)) value++;
    }
    return value;
}


int main()
{
    FILE *file=fopen("input.txt","r");
    printf("Result: %d.\n",part_1(file));
    rewind(file);
    printf("Result: %d.\n",part_2(file));
}