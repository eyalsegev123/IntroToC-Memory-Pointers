#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int addr5; //static storage - data segment
int addr6; //static storage - data segment

int foo() //code segment
{
    return -1;
}
void point_at(void *p);
void foo1(); //code segment
char g = 'g'; //static storage - data segment
void foo2(); //code segment

int secondary(int x)
{
    int addr2; //stack
    int addr3; //stack
    char *yos = "ree"; //static storage - data segment
    int *addr4 = (int *)(malloc(50)); //address is static, value on the heap
	int iarray[3]; //stack
    float farray[3]; //stack
    double darray[3]; //stack
    char carray[3]; //stack
	int iarray2[] = {1,2,3}; //stack
    char carray2[] = {'a','b','c'}; //stack
    int* iarray2Ptr;  //stack
    char* carray2Ptr; //stack
    
	printf("- &addr2: %p\n", &addr2);
    printf("- &addr3: %p\n", &addr3);
    printf("- foo: %p\n", &foo);
    printf("- &addr5: %p\n", &addr5);
	printf("Print distances:\n");
    point_at(&addr5);

    printf("Print more addresses:\n");
    printf("- &addr6: %p\n", &addr6);
    printf("- yos: %p\n", yos);
    printf("- gg: %p\n", &g);
    printf("- addr4: %p\n", addr4);
    printf("- &addr4: %p\n", &addr4);

    printf("- &foo1: %p\n", &foo1);
    printf("- &foo1: %p\n", &foo2);
    
    printf("Print another distance:\n");
    printf("- &foo2 - &foo1: %ld\n", (long) (&foo2 - &foo1));

   
    printf("Arrays Mem Layout (T1b):\n");
    
    printf("iarray:   %p\n", (void *)iarray);
    printf("iarray+1: %p\n", (void *)(iarray + 1));

    printf("farray:   %p\n", (void *)farray);
    printf("farray+1: %p\n", (void *)(farray + 1));

    printf("darray:   %p\n", (void *)darray);
    printf("darray+1: %p\n", (void *)(darray + 1));

    printf("carray:   %p\n", (void *)carray);
    printf("carray+1: %p\n", (void *)(carray + 1));
    
    printf("Pointers and arrays (T1d): \n");

    iarray2Ptr = &iarray2[0];
    carray2Ptr = &carray2[0];   
    void *p;
    printf("iarray2Ptr[0]: %d\n" , *iarray2Ptr);
    printf("iarray2Ptr[1]: %d\n" , *(iarray2Ptr + 1));
    printf("iarray2Ptr[2]: %d\n" , *(iarray2Ptr + 2));
    printf("iarray2Ptr[0]: %c\n" , *carray2Ptr);
    printf("iarray2Ptr[1]: %c\n" , *(carray2Ptr + 1));
    printf("iarray2Ptr[2]: %c\n" , *(carray2Ptr + 2));

    printf("Value of uninitialized pointer p: %p\n", p);

}

int main(int argc, char **argv)
{ 

    printf("Print function argument addresses:\n");

    printf("- &argc %p\n", &argc); //stack
    printf("- argv %p\n", argv); //stack
    printf("- &argv %p\n", &argv); //stack
	
	secondary(0);
    
    printf("Command line arg addresses (T1e):\n");
    printf("-Address of array argv: %p, content: %s\n", (void *)(argv), argv);
    for (int i = 0; i < argc; i++)
    {
        printf("-Address of argv[%d]: %p, content: %s\n", i, (void *)(argv + i), argv[i]);
    }
    
    return 0;
}

void point_at(void *p)
{
    int local; //stack
    static int addr0 = 2; //static storage - data segment
    static int addr1; //static storage - data segment

    long dist1 = (size_t)&addr6 - (size_t)p; //stack
    long dist2 = (size_t)&local - (size_t)p; //stack
    long dist3 = (size_t)&foo - (size_t)p; //stack

    printf("-dist of addr6-addr5: %ld\n", dist1);
    printf("-dist of local-addr5: %ld\n", dist2); //local is uninitialized
    printf("-dist of foo-addr5: %ld\n", dist3);
        
    printf("Check long type mem size (T1a):\n");
    size_t size_of_long = sizeof(long);
    printf("-Size of long: %zu bytes\n", size_of_long);
    printf("- addr0: %p\n", &addr0);
    printf("- addr1: %p\n", &addr1);
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}