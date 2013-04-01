#include "resize.hpp"

namespace Salmon {

#if defined(SDL_BACKEND)
	Resize Resize::translateEvent(SDL_WindowEvent &sdlEvent)
	{
		Resize res;
		res.size.setSize(sdlEvent.data1, sdlEvent.data2);
		return res;
	}
#endif //SDL_BACKEND
}
