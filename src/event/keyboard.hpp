#ifndef SALMON_KEYBOARD_HPP_
#define SALMON_KEYBOARD_HPP_

#include <SDL2/SDL_events.h>
#include "event.hpp"

namespace Salmon
{

	/**
	 * @brief Handles keyboard events.
	 */
	class Keyboard : public Event
	{
	public:

		/**
		 * @brief All keyboard characters that are supported.
		 */
		enum Code {
			a, b, c, d, e, f, g, h, i, j, k, l, m,
			n, o, p, q, r, s, t, u, v, w, x, y, z,
			num0, num1, num2, num3, num4, num5, num6, num7, num8, num9,
			escape, space, enter,

			lctrl, rctrl, lshift, rshift, lsystem, rsystem, lalt, ralt,

			tab, capslock, period, comma, backspace, semicolon,

			down, up, left, right,

			F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
			unknown, none
		};

		Code code = none; /**< Key that been pressed. */
		bool alt = false; /**< If any of alt keys has been pressed. */
		bool ctrl = false; /**< If any of ctrl keys has been pressed. */
		bool system = false; /**< If any of system keys has ben pressed. */

		/**
		 * @brief Default constructor.
		 */
		Keyboard();

		/**
		 * @brief Just sets the key code.
		 * @param code Code to be set.
		 */
		Keyboard(Code code);

		/**
		 * @brief Sets datafields of structure.
		 * @param code to set.
		 * @param alt If alt key is being pressed.
		 * @param ctrl If ctrl key is being pressed.
		 * @param system If systemkey is being pressed.
		 */
		Keyboard(Code code,
		         bool alt,
		         bool ctrl,
		         bool system);

		/**
		 * @brief Translates an event.
		 * @param sdlEvent SDL event to translate.
		 * @returns Translated structure.
		 */
#if defined(SDL_BACKEND)
		static Keyboard TranslateEvent(SDL_KeyboadEvent &sdlEvent);
#endif //defined(SDL_BACKEND)
	};

}

#endif // SALMON_KEYBOARD_HPP_
