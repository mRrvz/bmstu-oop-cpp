#ifndef __BASE_CONTAINTER_H__
#define __BASE_CONTAINTER_H__

class base_container
{
public:
    virtual bool is_empty() const = 0;
    virtual size_t size() const = 0;
    virtual void clear() = 0;
};

#endif
