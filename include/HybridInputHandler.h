/* Interface Definition: InputHandler
 * Author: Bhrathan Rajaram
 * This file defines the InputHandler interface. All classes which intend to recieve input and do something
 * meaningful with it must derive from the InputHandler class and register with the InputListenr. 
 * Input handler defines methods to handle events, which can be ignored or overridden.
 */

#ifndef HYBRID_INPUT_HANDLER_H
#define HYBRID_INPUT_HANDLER_H

namespace HybridRenderer
{

	class InputHandler
	{
		// Functions to deal with mouse input.
		virtual bool mouseMoved(const OIS::MouseEvent &evt) 
		{
			return true;
		}
		
		virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID);
		{
			return true;
		}
		
		virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID);
		{
			return true;
		}

		// Functions to deal with keyboard input.
		virtual bool keyPressed(const OIS::KeyEvent &evt);
		{
			return true;
		}
		
		virtual bool keyReleased(const OIS::KeyEvent &evt);
		{
			return true;
		}
	};
}

#endif
