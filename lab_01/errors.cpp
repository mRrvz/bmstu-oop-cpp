#include "errors.h"

void handle_error(const err_t &code)
{
    switch (code)
    {
        case FILE_ERR:
            QMessageBox::critical(nullptr, "Ошибка", "При открытии файла произошла ошибка.");
            break;
        case ALLOC_ERR:
            QMessageBox::critical(nullptr, "Ошибка", "При выделении памяти произошла ошибка.");
            break;
        case READ_ERR:
            QMessageBox::critical(nullptr, "Ошибка", "При чтении файла произошла ошибка.");
            break;
        case PSIZE_ERR:
            QMessageBox::critical(nullptr, "Ошибка", "Некорретный размер количества точек.");
            break;
        case LSIZE_ERR:
            QMessageBox::critical(nullptr, "Ошибка", "Некорректный размер количества линий.");
            break;
        default:
            break;
    }
}
