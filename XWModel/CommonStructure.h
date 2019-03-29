#pragma once
#include "boost\property_tree\ptree.hpp"
#include "boost\property_tree\json_parser.hpp"
#include <memory>


#define QUOTES(x) #x
#define PROPERTY_TREE_PUT(pt,v) {(pt).put(std::string(QUOTES(v)), std::to_string(v));}
#define PROPERTY_TREE_PUT_STRING(pt,v) {(pt).put(std::string(QUOTES(v)), std::string(v));}

#define PROPERTY_TREE_PUT_RAW(pt, n, v) {(pt).put((n), (v));}
#define PROPERTY_TREE_PUT_VALUE_STRING(pt,v) {(pt).put_value(std::string(v));}
#define PROPERTY_TREE_PUT_VALUE(pt,v) {(pt).put_value(std::to_string(v));}

using boost::property_tree::ptree;
