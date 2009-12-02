#include"HybridStateManager.h"
#include"HybridStateManagerInputHandler.h"
#include"OISEvents.h"

namespace HybridRenderer
{
        StateManagerInputHandler::StateManagerInputHandler(StateManager *stMgr)  
	{
		stateManager = stMgr;
	}

        StateManagerInputHandler::~StateManagerInputHandler() 
        {
		//The state manager is a shared resource.
		//Deletion is handled elsewhere
		//A smart pointer might be better for the state manager 
		//- think about it.
        }

	bool StateManagerInputHandler::keyPressed(const OIS::KeyEvent& evt)
	{
		if(evt.key == OIS::KC_ESCAPE)
			stateManager->requestStateChange(SHUTDOWN);
		else if(evt.key == OIS::KC_R)
			stateManager->requestStateChange(RAY_TRACE);
		else if(evt.key == OIS::KC_O)
			stateManager->requestStateChange(RASTERIZE);
		else if(evt.key == OIS::KC_C)
			stateManager->requestStateChange(DRAW_COMBINED);
	}		
}
