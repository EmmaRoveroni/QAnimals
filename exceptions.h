#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
class exceptions:public std::exception
{
public:
    class inputnotok{};
    class iddoppio{};
};

#endif // EXCEPTIONS_H
