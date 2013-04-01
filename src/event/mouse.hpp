#ifndef SALMON_MOUSE_HPP_
#define SALMON_MOUSE_HPP_

#include <SDL2/SDL_events.h>
#include "event.hpp"
#include "../gom/location.hpp"

#include <cstdint>

namespace Salmon
{

	/**
	 * @brief The mouse class
	 */
	class Mouse : public Event
	{
	public:
		/**
		 * @brief All mouse buttons.
		 */
		enum Button {
			unknown = 0b0000, /**< If unknown button has been pressed. */
			none =    0b0001, /**< If non of the keys was pressed. */
			left =    0b0010, /**< The left mouse button. */
			right =   0b0100, /**< The right mouse button. */
			middle =  0b1000  /**< The middle button. */
		};

		uint8_t button = none; /**< What buttons are pressed. */
		Location<int> location; /**< Location of mouse relative to the
		                           window. */
		Location<int> relLocation; /**< Relative motione event. */

		/**
		 * @brief Checks if button is pressed.
		 * @btn The button to check.
		 * @returns True if button is pressed else false.
		 */
		bool isPressed(Button btn);

#if defined(SDL_BACKEND)
		/**
		 * @brief Translates an SDL button event.
		 * @param sdlEvent Event to translate.
		 * @returns Translated SDL event to Salmon::Mouse.
		 */
		static Mouse translateEvent(SDL_MouseButtonEvent &sdlEvent);

		/**
		 * @brief Translates an SDL mouse motion event.
		 * @param sdlEvent Event to translate.
		 * @returns Translated SDL mouse motion event to Salmon::Mouse
		 */
		static Mouse translateEvent(SDL_MouseMotionEvent &sdlEvent);
#endif //SDL_BACKEND
	};

}

#endif
