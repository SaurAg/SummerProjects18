#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[])
{
	FILE *fp1,*fp2,*fp3;
	int l,k,i,j;
	char c,word[15],key[10],msg[15];
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");	
	fp3 = fopen(argv[3], "w");
	fscanf(fp2, " %s", key);
	fclose(fp2);	
	k=strlen(key);
    j=0;
	while (feof(fp1)==0)
	{
		fscanf(fp1, " %s", word);
		l=strlen(word);
        for (i=0;i<l;i++,j++)
			{
                if (j==k)
                    j=0;
				c=word[i]-key[j];
				if (c<=0)
					c=c+26;
				msg[i]=c+96;
			}
        msg[i]='\0';
        if (feof(fp1)==0)    
		    fprintf(fp3, "%s ", msg);
    }
	fclose(fp1);
	fclose(fp3);
}