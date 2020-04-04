#ifndef __SET_BASE_H__
#define __SET_BASE_H__

class baseSet
{
public:
    virtual void clear() = 0;
    virtual bool is_empty() = 0;
    virtual size_t size() = 0;
};

#endif
