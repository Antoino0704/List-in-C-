#include <iostream>

using namespace std;

namespace Exception
{
    class ListNotInitException : exception
    {
        public:
            const char* what() const throw() 
            {
                return "List Not Init Exception\n";
            }
    };
    class PositionException : exception
    {
        public:
            const char* what() const throw() 
            {
                return "Position Exception\n";
            }
    };
}