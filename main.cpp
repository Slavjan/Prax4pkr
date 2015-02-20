#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int max(int a, int b);
int ilen(int);

int main()
{
	errno_t err;
	
	int count_lines = 0,
		max_count_simbols = 0;

	FILE *f;

	err = fopen_s(&f, "Triangle.in", "rt");

	if (err == 0)
	{
		printf("The file 'crt_fopen_s.c' was opened\n\n");
	}
	else
	{
		printf("The file 'crt_fopen_s.c' was not opened\n\n");
		system("pause");
		return 0;
	}

	int i_x = 0, i = 0, j = 0;
	char result_string[20];
	while (fgets(result_string, sizeof(result_string), f))
	{
		count_lines++;

		//cout << sscanf_s(result_string, "%i", &x) << endl;
		for (char* start = result_string, c_x[128]; 
			sscanf_s(result_string, "%i", &i_x) == 1, sscanf_s(result_string, "%s", c_x);
			 start = strstr(start, c_x) + ilen(i_x))
		{
			max_count_simbols = max(max_count_simbols, strlen(result_string));
			max_count_simbols++;
			cout << max_count_simbols;
		}
		
		/*(sscanf_s(result_string, "%i", &x))
		{
			
			max_count_simbols++;
			cout << max_count_simbols;
		}*/ 

	}
												  // sscanf
	fclose(f);

	// int **A = new int[count_lines];
	// for(int i = 0; i < count_lines; i++)
	//     A[i] = new int [max_count_simbols];

	// char *real_tail;

	//     while(fgets(result_sting,sizeof(result_sting),f))
	//     {
	// 		count_lines++;
	// 		while( fscanf('%i', f) == 1)
	// 		{
	// 		    max_count_simbols = max(max_count_simbols,strlen(result_sting));
	// 		    max_count_simbols++;
	// 		}
	//     }

	cout << count_lines << " : " << max_count_simbols << endl;

	system("pause");

	return 0;
}

int max(int a, int b)
{
	return (a>b) ? a : b;

}

int ilen(int a)
{
	int i = 0;

	do
	{
		a %= 10;
		i++;
	} while (a != 0);

	return i;
}