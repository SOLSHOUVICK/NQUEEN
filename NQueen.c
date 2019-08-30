#include<stdio.h>
#define MAX 10
int Q[MAX+1]={0}, sol=1,dim;
int isSafe(int row, int col)
{
	int loop;
	for(loop=1;loop<=row-1;loop++)
		if((Q[loop]==col) || (abs(Q[loop]-col)==abs(loop-row)))
			return 0;
	return 1;
}
void NQueen(int row)
{
	int col,index,loop1,loop2;
	for(col=1;col<=dim;col++)
	{
		if(isSafe(row,col))
		{
			Q[row]=col;
			if(row==dim)
			{
				int solmat[MAX+1][MAX+1]={0};
				printf("\n\nSolution %d:\n\n",sol);
				for(index=1;index<=dim;index++)
					solmat[index][Q[index]]=1;
				for(loop1=1;loop1<=dim;loop1++)
				{
					for(loop2=1;loop2<=dim;loop2++)
					{
						if(solmat[loop1][loop2]==1)
							printf(" Q ");
						else
							printf(" * ");
					}
					printf("\n\n");
						
				}
				sol++;
			}
			else
				NQueen(row+1);
		}
	}
}
int main()
{
	printf("\nENTER THE DIMENSION OF THE CHESS BOARD:\t");
	scanf("%d",&dim);
	if(dim<4)
		printf("Solution Not Possible");
	else if(dim>10)
		printf("To big dimension Solution not possible");
	else
		NQueen(1);
}
