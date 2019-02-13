#include <pluginlib/class_list_macros.h>

#include "pluginlib_tutorial/polygon_base.hpp"
#include "pluginlib_tutorial/polygon_plugin.hpp"

PLUGINLIB_EXPORT_CLASS(polygon_plugins::Triangle, polygon_base::RegularPolygon)
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Square, polygon_base::RegularPolygon)

