#include "BaseController.h"



BaseController::BaseController(BaseView * p_view, ModelObject * p_model)
	:
	_view(p_view), _model(p_model)
{

}

BaseController::~BaseController()
{
	_view = nullptr;
	_model = nullptr;
}
