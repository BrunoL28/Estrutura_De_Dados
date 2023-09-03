#include "../include/utils.hpp"

std::string formatValue ( double value, int decimal ) {

    std::string string = std::to_string( value );
    size_t pos = string.find( '.' );

    if ( pos == std::string::npos ) {
        string += '.';
        pos = string.size() - 1;
    }

    int zeroes = decimal - ( string.size() - pos - 1 );
    for ( int i = 0; i < zeroes; i++ ) {
        string += '0';
    }

    return string;
}