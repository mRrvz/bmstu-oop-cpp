#include "loader.h"

std::shared_ptr<model> model_loader::load_model(base_builder &builder)
{
    builder.build();

    size_t points_count;
    this->file >> points_count;

    for (size_t i = 0; i < points_count; i++)
    {
        double x, y, z;
        this->file >> x >> y >> z;
        builder.build_point(x, y, z);
    }

    size_t links_count;
    this->file >> links_count;


    for (size_t i = 0; i < links_count; i++)
    {
        size_t pt1, pt2;
        this->file >> pt1 >> pt2;
        builder.build_link(pt1, pt2);
    }

    return builder.get();
    //fclose();
}

void model_loader::fopen(std::string &fname)
{
    this->file.open(fname);
    qDebug() << "correct open";
    if (!this->file)
    {
        qDebug() << "fail fileopen";
        // throw
    }

}

void model_loader::fclose()
{
    try
    {
        this->file.close();
    } catch (std::ifstream::failure &error)
    {
        qDebug() << "fail close";
    }
}
