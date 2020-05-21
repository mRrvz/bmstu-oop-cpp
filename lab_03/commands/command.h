#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H


class base_command
{
public:
    base_command();
    virtual ~base_command() = default;
    virtual void execute() = 0;
};

#endif
