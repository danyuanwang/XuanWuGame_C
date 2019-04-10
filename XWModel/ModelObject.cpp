#include "ModelObject.h"

unsigned long ModelObject::s_id_counter = 0;

ModelObject::ModelObject()
{
	_id = ++s_id_counter;

}


ModelObject::~ModelObject()
{
}


std::string ModelObject::ToJson()
{
	std::stringstream json;

	boost::property_tree::write_json(json, _property_tree);

	return json.str();
}
