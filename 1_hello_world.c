#include<stdio.h>
#include<omp.h>

int main( int *arg, char *argv[] )
{

#pragma omp parallel
{
printf( "Hello World!\n") ;
}
return 0;
}
