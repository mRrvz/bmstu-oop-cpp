#include "links.h"

static err_t read_amount(ldata_t &links, FILE *f)
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

static err_t read_links(link_t *const array, const int &size, FILE *f)
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

    if (temp_array == NULL)
    {
        return ALLOC_ERR;
    }

    links.array = temp_array;

    return OK;
}

void free_links(const ldata_t &links)
{
    if (links.array != NULL)
    {
        free(links.array);
    }
}

err_t handle_links(ldata_t &links, FILE *f)
{
     err_t error_code = OK;

     if ((error_code = read_amount(links, f)))
     {
         return error_code;
     }

     if ((error_code = allocate_links(links)))
     {
         return error_code;
     }

     if ((error_code = read_links(links.array, links.size, f)))
     {
         free_links(links);
     }

     return error_code;
}
