#include <errno.h>
#include <stdio.h>

void test2(int x)
{
	errno = x;
}

void test(int x)
{
	test2(x);
}

int main()
{
	test(12);
	perror(__func__);
}