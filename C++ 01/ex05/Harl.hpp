#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
public:
    void    complain( std::string level );
    void (*f[4])(void);
    std::string level[4];

private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );
};

#endif