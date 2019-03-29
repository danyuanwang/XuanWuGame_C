#include"CommonStructure.h"

int CommonStructure::PropertyTreeWalker::IteratePropertyTree(ptree pt, PropertyTreeWalker* pcallback)
{
	return _iteratePropertyTree(pt, pcallback, 0);
}

int CommonStructure::PropertyTreeWalker::_iteratePropertyTree(ptree pt, PropertyTreeWalker* pcallback, int level)
{
	int local_level = 0;

	// tree is a boost::property_tree::ptree
	BOOST_FOREACH(boost::property_tree::ptree::value_type const&v, pt)
	{
		const std::string & key = v.first; // key
		const boost::property_tree::ptree & subtree = v.second; // value (or a subnode)
		if (subtree.empty())
		{
			// This is a key:value
			//  use subtree.data() as string value or subtree.get_value<T>()
			pcallback->OnIterateCallback(key, subtree.data(), level);
		}
		else
		{
			// This is a subtree
			//  use subtree as child
			pcallback->OnIterateCallback(std::string{}, key, level);

			local_level = _iteratePropertyTree(subtree, pcallback, level + 1);
		}
	}

	return level + local_level;

}
