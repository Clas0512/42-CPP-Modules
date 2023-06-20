#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
public:
    void    complain( std::string level );
    std::string level[4];
    void (Harl::*f[4])(void);
private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );
};

#endif