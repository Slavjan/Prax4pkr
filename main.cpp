#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int max(int a, int b);
int ilen(int);

class Node
{
public:
	int x;

	Node *ln;
	Node *rn;

	void operator =(Node a)
	{
		this->x = a.x;
	}
	void operator =(Node* a)
	{
		x = a->x;
	}


	Node(int _x = 0)
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

int main()
{
	int x, i = 0, n = 1;
	FILE* f;
	fopen_s(&f, "Triangle.in", "rt");

	Node *Tree = new Node [100];

	while ( fscanf_s(f,"%i",&x)==1 )						//i+1*j
	{			
		Tree[i].x = x;
	
		if (i%2 == 0 && i != 0)
		{
			Tree[i - 1].rn->operator=(Tree[i]);
		}
		else if (i % 2 != 0 && i != 0)
		{
			Tree[i - 1].ln->operator=(Tree[i]);
		}

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

