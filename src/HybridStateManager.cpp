#include "HybridStateManager.h"

namespace HybridRenderer
{
	StateManager::StateManager()
	{
		state = STARTUP;
	}

	StateManager::~StateManager()
	{
	}
	
	bool StateManager::requestStateChange(ApplicationState newState)
	{
		if(state == STARTUP)
		{
			locked = false;
			state = newState;
			return true;
		}

		else if(state == SHUTDOWN)
		{
			return false;
		}

		else if ((state == RASTERIZE) || (state == RAY_TRACE ) || \
			(state == DRAW_COMBINED))
		{
			state = newState;
			return true;
		}

	}
        
	// for the sake of clarity, I am not using actual thread synchronization 
        // objects to serialize access to this resource. You would want to protect
        // this block with a mutex or critical section, etc.
        bool StateManager::lockState() 
        {
	        if (locked == false) 
	        {
        		locked = true;
        		return true;
	        }
	        else
		        return false;
        }

        bool StateManager::unlockState() 
        {
	        if (locked == true) 
	        {
		        locked = false;
		        return true;
	        }
	        else
		        return false;
        }

	ApplicationState StateManager::getCurrentState()
	{
		return state;
	}

}
