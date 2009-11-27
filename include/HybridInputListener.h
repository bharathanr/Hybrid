#include "OISEvents.h"
#include "OISInputManager.h"
#include "OISMouse.h"
#include "OISKeyboard.h"

namespace HybridRenderer
{
	class InputListener: public KeyboardListener, public MouseListener
	{
	};
}
