#include "HybridStateManager.h"

namespace HybridRenderer
{
	StateManager::StateManager()
	{
		m_state = STARTUP;
	}

	StateManager::~StateManager()
	{
	}
	
	bool StateManager::requestStateChange(ApplicationState newState)
	{
		if(m_state == STARTUP)
		{
			m_locked = false;
			m_state = newState;
			return true;
		}

		else if(m_state == SHUTDOWN)
		{
			return false;
		}

		else if ((m_state == RASTERIZE) || (m_state == RAY_TRACE ) || \
			(m_state == DRAW_COMBINED))
		{
			m_state = newState;
			return true;
		}

	}
        
	// for the sake of clarity, I am not using actual thread synchronization 
        // objects to serialize access to this resource. You would want to protect
        // this block with a mutex or critical section, etc.
        bool StateManager::lockState() 
        {
	        if (m_locked == false) 
	        {
        		m_locked = true;
        		return true;
	        }
	        else
		        return false;
        }

        bool StateManager::unlockState() 
        {
	        if (m_locked == true) 
	        {
		        m_locked = false;
		        return true;
	        }
	        else
		        return false;
        }

	ApplicationState StateManager::getCurrentState()
	{
		return m_state;
	}

}
