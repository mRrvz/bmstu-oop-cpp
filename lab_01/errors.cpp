#include "errors.h"

void handle_error(const err_t &code)
{
    switch (code)
    {
        case FILE_ERR:
            QMessageBox::critical(NULL, "Ошибка", "При открытии файла произошла ошибка.");
            break;
        case ALLOC_ERR:
            QMessageBox::critical(NULL, "Ошибка", "При выделении памяти произошла ошибка.");
            break;
        case READ_ERR:
            QMessageBox::critical(NULL, "Ошибка", "При чтении файла произошла ошибка.");
            break;
        case PSIZE_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Некорретный размер количества точек.");
            break;
        case LSIZE_ERR:
            QMessageBox::critical(NULL, "Ошибка", "Некорректный размер количества линий.");
            break;
        default:
            break;
    }
}
