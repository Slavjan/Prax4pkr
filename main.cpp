#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int max(int a, int b);
int ilen(int);

class Node;

int main()
{
	int x, i = 0, n = 1;
	FILE* f;
	fopen_s(&f, "Triangle.in", "rt");

	Node** Tree = new Node* [100];

	while ( fscanf(f,"%i",&x)==1 )						//i+1*j
	{
		
		if (!Tree[i])
		{
			Tree[i] = new Node(x);		  
		}
		else
		{
			Tree[i]->x = x;
		}
		Tree[i + 1] = new Node(0);
		Tree[i + 2] = new Node(0);
/*
		if (j = 0)
		{
		   Tree[j - 1]->ln = Tree[i];
		}
		if (j = 1)
		{
			Tree[j - 1]->ln = Tree[i];
			Tree[j - 1]->rn = Tree[i + 1];
		}
*/
		i++;
	}
	fclose(f);

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

class Node
{
public:
	int x;

	Node *ln;
	Node *rn;

	Node(int _x)
	{
		ln = NULL;
		rn = NULL;
		x = _x;
	}

	int go()
	{
		return 0;
	}
};