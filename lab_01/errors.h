#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

enum errors
{
    OK,
    FILE_ERR,
    ALLOC_ERR,
    READ_ERR,
    LSIZE_ERR,
    PSIZE_ERR
};

using err_t = enum errors;

void handle_error(const err_t code);

#endif
