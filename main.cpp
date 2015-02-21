#include <stdio.h>
#include <string.h>
#include <iostream>

//#define VS

using namespace std;

int max(int a, int b){
    return (a>b)? a : b;
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

//	void operator =(Node a)
//	{
//        x = a.x;
//	}
//	void operator =(Node* a)
//	{
//		x = a->x;
//	}


	Node(int _x = 0)
	{
		ln = NULL;
		rn = NULL;
		x = _x;
	}

	int go()
	{
        if( ln == NULL || rn == NULL )
            return x;
        else
            return max( ln->go(), rn->go() );
	}
};

int main()
{
    char* fileIn = "Triangle.in";
    char* fileOut = "Triangle.out";
	int x, i = 0, n = 1;
	FILE* f;
    #ifdef VS
        fopen_s(&f, fileIn, "rt");
    #else
        f = fopen(fileIn, "rt");
    #endif

    if( f == 0 ){
        printf("File '%s' is not exists", fileIn);
        return 1;
    }

	Node *Tree = new Node [100];

    #ifdef VS
        while ( fscanf_s(f,"%i",&x)==1 )						//i+1*j
    #else
        while( fscanf(f, "%i", &x) == 1 )
    #endif
	{			
		Tree[i].x = x;
	
        // Вот, это была вакханалия...
        // я долго ржал :D
        // ...
        // а потом понял что без неё не работает ...
        // Немного подумав... я задался вопросом
        // а на хера мне вообще это сдалось
		if (i%2 == 0 && i != 0)
		{
            Tree[i - 1].rn = Tree[i];
		}
		else if (i % 2 != 0 && i != 0)
		{
            Tree[i - 1].ln = Tree[i];
		}

		i++;
	}
	fclose(f);

	return 0;
}
