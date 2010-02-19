/*
   Copyright 2010 Bharathan Rajaram

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include<boost/signal.hpp>

/* The InputSystem class is an interface that
 * declares Boost events that must be raised 
 * by all InputSystem's. For a concrete example
 * see the OISInputSystem class.
 */

class InputSystem
{
	public:
		//Public signal declarations
		boost::signal<void ()> HelloWorld;
};


#endif
