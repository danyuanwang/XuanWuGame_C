#pragma once
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include <boost/foreach.hpp>
#include <memory>


#define QUOTES(x) #x
#define PROPERTY_TREE_PUT(pt,v) {(pt).put(std::string(QUOTES(v)), std::to_string(v));}
#define PTREE_PUT(v)  PROPERTY_TREE_PUT(_property_tree,v)
#define PROPERTY_TREE_PUT_STRING(pt,v) {(pt).put(std::string(QUOTES(v)), std::string(v));}
#define PROPERTY_TREE_PUT_RAW(pt, n, v) {(pt).put((n), (v));}

#define PROPERTY_TREE_GET(pt, v, t) {(v) = (t)std::atoi((pt).get(std::string(QUOTES(v)), "").c_str());}
#define PTREE_GET_T(v, t) PROPERTY_TREE_GET(_property_tree, v, t)
#define PTREE_GET(v) PROPERTY_TREE_GET(_property_tree, v, int)
#define PROPERTY_TREE_GET_STRING(pt, v) {(v) = (pt).get(std::string(QUOTES(v)), "");}


//#define PROPERTY_TREE_PUT_VALUE_STRING(pt,v) {(pt).put_value(std::string(v));}
//#define PROPERTY_TREE_PUT_VALUE(pt,v) {(pt).put_value(std::to_string(v));}
//

//#define MATCH_FROM_PROPERTY_KV(k,v,x,T) if (k == QUOTES(x)) \
//{\
//	x = (T)std::atoi(v.c_str());\
//}\
//

using boost::property_tree::ptree;

namespace CommonStructure
{
	class PropertyTreeWalker
	{
	public:
		virtual void OnIterateCallback(std::string key, std::string value, int level) = 0;

		/*
			if key is empty, then it is a root node of substrees
		*/

		static int IteratePropertyTree(ptree pt, PropertyTreeWalker* pcallback/*using ordinary pointer means no ownership*/);

	private:
		static int _iteratePropertyTree(ptree pt, PropertyTreeWalker* pcallback, int level);

	};
}
