#pragma once
#include "GamePlayRequest.h"
#include "ModelObject.h"

class ServerBaseController
{
public:
	virtual ~ServerBaseController();
	virtual void HandleGameRequest(GamePlayRequest& gpr) = 0;
	
protected:
	ServerBaseController(ModelObject* p_model);
	ModelObject* _p_model;
};
