#ifndef __BASE_CONTAINTER_H__
#define __BASE_CONTAINTER_H__

class base_container
{
public:
    virtual bool is_empty(void) const = 0;
    virtual size_t get_size(void) const = 0;
    virtual void clear(void) = 0;
};

#endif
