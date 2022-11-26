#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char *args[])
{
	FILE *temp;
  	temp = fopen("temp.c","w");
	FILE *current;
	char c;
	char p;
	char *name = (char*)malloc(sizeof(char)*200);
	for(int i=1;i<argv;i++)
	{
		current = fopen(args[i],"r");
		int pass= 0;
		int block =0;
		int inString = 0;
		int inComment = 0;
		do{
			p = c;
			c = fgetc(current);
			if(c == EOF) break;
			if(c == '"' && inString) inString =0;
			else if(c=='"') inString =1;
			if(p == c && c == '/' && inString==0) pass=1;
			if(p=='/' && c== '*' && inString ==0){ pass=1; block=1;}
			if(p=='*' && c=='/'){ pass=0; block=0;}
			if(c=='\n' && block ==0) pass =0;
			if(pass==0 && ((c!='/' && p!='/')|| (c!='/' && p!='*') || inString==1 ))
			{
				fprintf(temp,"%c",c);
			}
			
	
	
		}while(1);


	}
	


return 0;
}
