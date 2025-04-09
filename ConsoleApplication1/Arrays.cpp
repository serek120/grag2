#include <array>
#include <string>
#include <cstdio>
#include <iostream>
#include "eq.h"

std::array<std::string, 10> EQ;

/*void ShowEQ()
{
	for(int i = 0; i < ( sizeof( EQ ) / sizeof( EQ[ 0 ] ) ); i++ )
	{
		printf( "%s\n", EQ[ i ] );
	}
}
*/

void ShowEQ()
{
    // Use the size() method to get the number of elements in the array
    for( int i = 0; i < EQ.size(); i++ )
    {
        // Print the element using std::cout (safer and more appropriate for std::string)
        std::cout << EQ[ i ] << std::endl;
    }
}