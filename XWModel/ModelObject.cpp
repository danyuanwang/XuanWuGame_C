#include "ModelObject.h"

unsigned long ModelObject::s_id_counter = 0;

ModelObject::ModelObject()
{
	_id = ++s_id_counter;

}


ModelObject::~ModelObject()
{
}
