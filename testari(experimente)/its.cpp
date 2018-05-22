#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#include <iostream>

int main()
{
        const int n=30;;
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;

}
