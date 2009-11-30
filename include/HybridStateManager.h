/*
 * Author: Bharathan Rajaram
 * This file implements a state manager for my application.
 * The application states are:
 * 1. STARTUP
 * 2. RASTERIZE
 * 3. RAY_TRACE
 * 4. DRAW_COMBINED
 * 5. SHUTDOWN
 */

#ifndef HYBRID_STATE_MANAGER_H
#define HYBRID_STATE_MANAGER_H

namespace HybridRenderer
{
	enum ApplicationState
	{
		STARTUP,
		RASTERIZE,
		RAY_TRACE,
		DRAW_COMBINED,
		SHUTDOWN
	};

	class StateManager
	{
		private:
			ApplicationState state;
			bool locked;
		public:
			StateManager();
			~StateManager();

			bool requestStateChange(ApplicationState state);
			//The next two functions should be useful when 
			//I multi thread.
			bool lockState();
			bool unlockState();
			ApplicationState getCurrentState();
	};
}

#endif
