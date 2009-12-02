#ifndef HYBRID_STATE_MANAGER_INPUT_HANDLER_H
#define HYBRID_STATE_MANAGER_INPUT_HANDLER_H

#include"OISEvents.h"

#include"HybridInputHandler.h"

namespace HybridRenderer
{
	class StateManager;

	class StateManagerInputHandler: public InputHandler
	{
		private:
			StateManager *stateManager;
		public:
			StateManagerInputHandler(StateManager *stMgr);
			~StateManagerInputHandler();
			bool keyPressed(const OIS::KeyEvent&);
	};
}

#endif
