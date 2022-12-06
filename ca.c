#include <windows.h>
#include <stdio.h>


int main(void)
{
	char cells[2][162];
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 162; j++)
		{
			cells[i][j] = 0;
		}
	}
	cells[0][80] = 1;
	unsigned char rule = ~22;

	while(1)
	{
		for(int i = 1; i < 161; i++)
		{
			cells[1][i] = 0;

			if(rule&0b10000000)
			{
				if (!(cells[0][i - 1]) && !(cells[0][i]) && !(cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}
			}
			if(rule&0b01000000)
			{
				if (!(cells[0][i - 1]) && !(cells[0][i]) && (cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}

			}
			if(rule&0b00100000)
			{
				if (!(cells[0][i - 1]) && (cells[0][i]) && !(cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}

			}
			if(rule&0b00010000)
			{
				if (!(cells[0][i - 1]) && (cells[0][i]) && (cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}

			}
			if(rule&0b00001000)
			{
				if ((cells[0][i - 1]) && !(cells[0][i]) && !(cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}

			}
			if(rule&0b00000100)
			{
				if ((cells[0][i - 1]) && !(cells[0][i]) && (cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}

			}
			if(rule&0b00000010)
			{
				if ((cells[0][i - 1]) && (cells[0][i]) && !(cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}

			}
			if(rule&0b00000001)
			{
				if ((cells[0][i - 1]) && (cells[0][i]) && (cells[0][i + 1]))
				{
					cells[1][i] = 1;
					goto end;
				}

			}
		end:;
		}


		for(int i = 0; i < 160; i++)
		{
			if(cells[0][i] == 1)
			{
				printf("\xDB");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");

		for(int i = 0; i<162;i++)
		{
			cells[0][i] = cells[1][i];
		}
	}

	return 0;
}

