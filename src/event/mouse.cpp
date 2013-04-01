#include "mouse.hpp"
#include <functional>

namespace Salmon
{
#if defined(SDL_BACKEND)
	static Mouse Mouse::translateEvent(SDL_MouseButtonEvent &sdlEvent)
	{
		Mouse ev;
		switch(sdlEvent.button) {
		case SDL_BUTTON_LEFT: ev.button = left; break;
		case SDL_BUTTON_MIDDLE: ev.button = middle; break;
		case SDL_BUTTON_RIGHT: ev.button = right; break;
		default: ev.button = unknown; break;
		}

		ev.location.setLocation(sdlEvent.x, sdlEvent.y);
		ev.relLocation.setLocation(0, 0);

		return ev;
	}

	static Mouse Mouse::translateEvent(SDL_MouseMotionEvent &sdlEvent)
	{
		Mouse ev;
		ev.location.setLocation(sdlEvent.x, sdlEvent.y);
		ev->relLocation.setLocation(sdlEvent.xrel, sdlEvent.yrel);
		auto maskComp = [] (Uint8 state, Uint8 mask) {
			if ((state & mask) == mask)
				return true;
			return false;
		};

		if (maskComp(sdlEvent.state, SDL_BUTTON_LMASK)) {
			ev.button |= left;
		}

		if (maskComp(sdlEvent.state, SDL_BUTTON_RMASK)) {
			ev.button |= right;
		}

		if (maskComp(sdlEvent.state, SDL_BUTTON_MMASK)) {
			ev.button |= middle;
		}

		if (ev.button > 0b0001) {
			ev.button &= 0b1110;
		}

		return ev:
	}
#endif //SDL_BACKEND

	bool Mouse::isPressed(Button btn)
	{
		if ((button & btn) == btn)
			return true;
		return false;
	}
}
