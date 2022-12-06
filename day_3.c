#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int convert_item(char x)
{
    int value=0;
    if(islower(x)!=0)
    {
        value=x-96;
    }
    else value=x-38;
    return value;
}

void divide_array(char *arr,char *half_1,char *half_2,int x)
{
    int i=0,y=x;
    while(i<y)
    {
        half_1[i]=arr[i];
        i++;
    }
    i=0;
    while(i<y)
    {
        half_2[i]=arr[x];
        x++;i++;
    }
}

char equal_test_2(char *arr_1,char *arr_2)
{
    int i=0,j=0;
    while(arr_1[i]!='\0')
    {
        while(arr_2[j]!='\0')
        {
            if(arr_1[i]==arr_2[j]) return arr_1[i];
            j++;
        }
        j=0;
        i++;
    }
    return arr_1[i];
}

char equal_test_3(char *arr_1,char *arr_2,char *arr_3)
{
    int i=0,j=0,l=0;
    while(arr_1[i]!='\0')
    {
        while(arr_2[j]!='\0')
        {
            while(arr_3[l]!='\0')
            {
                if(arr_1[i]==arr_2[j] && arr_1[i]==arr_3[l]) return arr_1[i];
                l++;
            }
            l=0;
            j++;
        }
        j=0;
        i++;
    }
    return arr_1[i];
}

int part_1(FILE *file)
{
    size_t size=0;
    ssize_t teste=0;
    int len=0,value=0;
    char *line=NULL;
    while((teste=getline(&line,&size,file))!=-1)
    {
        len=strlen(line);
        char *half_1=malloc(len*sizeof(char));
        char *half_2=malloc(len*sizeof(char));
        line[len]='\0';
        divide_array(line,half_1,half_2,len/2);
        value+=convert_item(equal_test_2(half_1,half_2));
    }
    return value;
}

int part_2(FILE *file)
{
    size_t size=0;
    ssize_t teste=0;
    int value=0,i=0;
    char *line=NULL,*arr_1,*arr_2,*arr_3;
    while((teste=getline(&line,&size,file))!=-1)
    {
        line[strlen(line)]='\0';
        if(i==0) arr_1=strdup(line);
        else if(i==1) arr_2=strdup(line);
        else if(i==2) 
        {    
            arr_3=strdup(line);
            value+=convert_item(equal_test_3(arr_1,arr_2,arr_3));
            i=-1;
        }
        i++;
    }
    return value;
}

int main()
{
    FILE *file=fopen("input.txt","r");
    printf("Sum of priorities: %d.\n",part_1(file));
    rewind(file);
    printf("Sum of priorities: %d.\n",part_2(file));
}