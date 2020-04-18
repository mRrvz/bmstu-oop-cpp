#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <exception>
#include <string>
#include <cstring>

class base_error : public std::exception
{
public:
    base_error(std::string time,
        std::string filename, std::string classname, std::string methodname)
    {
        error_info = "\nTime: " + time + \
                     "File: " + filename + \
                     "\nClass: " + classname + \
                     "\nMethod: " + methodname;
    }

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: Something is wrong with your list." + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }

protected:
    std::string error_info;
};

class memory_error : base_error
{
public:
    memory_error(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: Unable to allocate memory. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class empty_list : base_error
{
public:
    empty_list(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: List is empty. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class iterator_error : base_error
{
public:
    iterator_error(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: Invalid iterator. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class pointer_error : base_error
{
public:
    pointer_error(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: Invalid pointer. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class size_error: base_error
{
public:
    size_error(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        std::string message = "\nERROR: The size passed to the method is invalid." + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};


#endif
