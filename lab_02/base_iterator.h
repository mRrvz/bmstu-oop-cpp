#ifndef __BASE_ITERATOR_H__
#define __BASE_ITERATOR_H__

class base_iterator
{
    virtual void next(void) = 0;
    virtual bool is_invalid(void) const = 0;
};

#endif
