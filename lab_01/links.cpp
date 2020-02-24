#include "links.h"

static err_t read_amount(FILE *f, ldata_t &links)
{
    if ((fscanf(f, "%d", &links.size)) != 1)
    {
        return READ_ERR;
    }

    if (links.size < 1)
    {
        return LSIZE_ERR;
    }

    return OK;
}

static err_t read_links(FILE *f, const int &size, link_t *const array)
{
    for (int i = 0; i < size; i++)
    {
        if ((fscanf(f, "%d %d", &array[i].point_1, &array[i].point_2)) != 2)
        {
            return READ_ERR;
        }
    }

    return OK;
}

static err_t allocate_links(ldata_t &links)
{
    link_t *temp_array = (link_t *)malloc(links.size * sizeof(link_t));

    if (temp_array == nullptr)
    {
        return ALLOC_ERR;
    }

    links.array = temp_array;

    return OK;
}

void free_links(const ldata_t &links)
{
    if (links.array != nullptr)
    {
        free(links.array);
    }
}

err_t handle_links(FILE *f, ldata_t &links)
{
     err_t error_code;

     if ((error_code = read_amount(f, links)))
     {
         return error_code;
     }

     if ((error_code = allocate_links(links)))
     {
         return error_code;
     }

     if ((error_code = read_links(f, links.size, links.array)))
     {
         free_links(links);
         return error_code;
     }

     return OK;
}
