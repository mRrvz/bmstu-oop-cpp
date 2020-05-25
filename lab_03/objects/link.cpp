#include "link.h"

link::link(const link &_link)
{
    this->pt1_index = _link.pt1_index;
    this->pt2_index = _link.pt2_index;
}

link &link::operator=(const link &_link)
{
    this->pt1_index = _link.pt1_index;
    this->pt2_index = _link.pt2_index;

    return *this;
}

link::link(link &&_link)
{
    this->pt1_index = _link.pt1_index;
    this->pt2_index = _link.pt2_index;
    _link.~link();
}

link &link::operator=(link &_link)
{
    this->pt1_index = _link.pt1_index;
    this->pt2_index = _link.pt2_index;
    _link.~link();

    return *this;
}

size_t link::get_fst() const
{
    return this->pt1_index;
}

size_t link::get_snd() const
{
    return this->pt2_index;
}

void link::set_fst(const size_t &fst)
{
    this->pt1_index = fst;
}

void link::set_snd(const size_t &snd)
{
    this->pt2_index = snd;
}
