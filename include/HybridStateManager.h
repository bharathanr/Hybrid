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

namespace HybridRenderer
{
	typedef enum
	{
		STARTUP,
		RASTERIZE,
		RAY_TRACE,
		DRAW_COMBINED,
		SHUTDOWN
	} ApplicationState;

	class StateManager
	{
		private:
			ApplicationState m_state;
			bool m_locked;
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

