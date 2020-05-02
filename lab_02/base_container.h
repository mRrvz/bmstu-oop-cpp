#ifndef __BASE_CONTAINTER_H__
#define __BASE_CONTAINTER_H__

class base_container
{
public:
    virtual bool is_empty() const = 0;
    virtual void clear() = 0;
    virtual ~base_container() = default;

protected:
    size_t size;
};

#endif
