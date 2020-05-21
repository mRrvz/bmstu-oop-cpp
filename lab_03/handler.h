#ifndef HANDLER_H
#define HANDLER_H

#include <memory>

class abstract_handler
{
public:
    abstract_handler() : next(nullptr) {};
    virtual ~abstract_handler() = default;
    void add(std::shared_ptr<abstract_handler> node);
    void add(std::shared_ptr<abstract_handler> node1, std::shared_ptr<abstract_handler> node2, ...);

protected:
    std::shared_ptr<abstract_handler> next;
    virtual bool run() = 0;
};

class actions_handler : public abstract_handler
{
public:
    actions_handler() = default;

    virtual bool run() override;
};

#endif // HANDLER_H
