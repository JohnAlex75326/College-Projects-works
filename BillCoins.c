/* Name: John Alexander Sarmiento
* Subject Section: CS 11.1 A
* Description: Program that provides the smallest number of combination of bills and coins possible for a given amount
*/

#include<stdio.h>

int main()
{
	float input = 0;
	int ctr[15];
	float dosh = 0;
	int launch = 0;
	
	printf("This breaks down cash amount to the least possible combination.  \n");
	printf("Enter an amount:  ");
	scanf("%f", &input);
	
	
	dosh = input;
	
	for (ctr[0]= 0;ctr[0] >= 0;ctr[0]++)
	{
		if (dosh >= 1000)
		{
			dosh = dosh - 1000;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[1]= 0;ctr[1] >= 0;ctr[1]++)
	{
		if (dosh >= 500)
		{
			dosh = dosh - 500;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[2]= 0;ctr[2] >= 0;ctr[2]++)
	{
		if (dosh >= 100)
		{
			dosh = dosh - 100;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[3]= 0;ctr[3] >= 0;ctr[3]++)
	{
		if (dosh >= 50)
		{
			dosh = dosh - 50;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[4]= 0;ctr[4] >= 0;ctr[4]++)
	{
		if (dosh >= 20)
		{
			dosh = dosh - 20;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[5]= 0;ctr[5] >= 0;ctr[5]++)
	{
		if (dosh >= 10)
		{
			dosh = dosh - 10;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[6]= 0;ctr[6] >= 0;ctr[6]++)
	{
		if (dosh >= 5)
		{
			dosh= dosh - 5;
		}
		else
		{
			break;
		}
	}
	
	
for (ctr[7]= 0;ctr[7] >= 0;ctr[7]++)
	{
		if (dosh >= 1.00)
		{
			dosh = dosh - 1.00;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[8]= 0;ctr[8] >= 0;ctr[8]++)
	{
		if (dosh >= 0.50)
		{
			dosh = dosh - 0.50;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[9]= 0;ctr[9] >= 0;ctr[9]++)
	{
		if (dosh >= 0.25)
		{
			dosh = dosh - 0.25;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[10]= 0;ctr[10] >= 0;ctr[10]++)
	{
		if (dosh >= 0.10)
		{
			dosh = dosh - 0.10;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[11]= 0;ctr[11] >= 0;ctr[11]++)
	{
		if (dosh >= 0.05)
		{
			dosh = dosh - 0.05;
		}
		else
		{
			break;
		}
	}
	
	for (ctr[12]= 0;ctr[12] >= 0;ctr[12]++)
	{
		if (dosh >= 0.01)
		{
			dosh = dosh - 0.01;
		}
		else
		{
			break;
		}
	}
	
	launch = ctr[0] + ctr[1] + ctr[2] + ctr[3] + ctr[4] + ctr[5] + ctr[6] + ctr[7] + ctr[8] + ctr[9] + ctr[10] + ctr[11] + ctr[12];
	
	printf("Denominations:\n");
	printf("%d x 1000 \n",ctr[0]);
	printf("%d x 500 \n",ctr[1]);
	printf("%d x 100 \n",ctr[2]);
	printf("%d x 50 \n",ctr[3]);
	printf("%d x 20 \n",ctr[4]);
	printf("%d x 10 \n",ctr[5]);
	printf("%d x 5 \n",ctr[6]);
	printf("%d x 1 \n",ctr[7]);
	printf("%d x 0.50 \n",ctr[8]);
	printf("%d x 0.25 \n",ctr[9]);
	printf("%d x 0.10 \n",ctr[10]);
	printf("%d x 0.05 \n",ctr[11]);
	printf("%d x 0.01 \n",ctr[12]);
	

	printf("The smallest possible number of combination is %d.\n", launch);
}
