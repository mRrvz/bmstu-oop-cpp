#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <exception>
#include <string>

class base_error : public std::exception
{
public:
    base_error(std::string time,
        std::string filename, std::string classname, std::string methodname)
    {
        error_info = "Time: " + time + \
                     "\nFile: " + filename + \
                     "\nClass: " + classname + \
                     "\nMethod: " + methodname;
    }

    virtual const char* what() const noexcept override
    {
        return error_info.c_str();
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
        return ("Error while memory allocation. " + error_info).c_str();
    }
};

class empty_list : base_error
{
public:
    empty_list(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        return ("List is empty. " + error_info).c_str();
    }
};

class iterator_error : base_error
{
public:
    iterator_error(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        return ("Invalid iterator. " + error_info).c_str();
    }
};

class pointer_error : base_error
{
public:
    pointer_error(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        return ("Invalid pointer. " + error_info).c_str();
    }
};

class size_error: base_error
{
public:
    size_error(std::string time, std::string filename, std::string classname, std::string methodname) :
        base_error(time, filename, classname, methodname) {};

    virtual const char* what() const noexcept override
    {
        return ("The size passed to the method is invalid. " + error_info).c_str();
    }
};


#endif
