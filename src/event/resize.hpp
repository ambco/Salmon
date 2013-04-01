#ifndef RESIZE_HPP
#define RESIZE_HPP

#include <SDL2/SDL_events.h>

#include "event.hpp"
#include "../gom/size.hpp"

namespace Salmon {

/**
 * @brief Resize event.
 */
class Resize : public Event {
public:
    Size<int> size; /**< Resize request size. */

    /**
     * @brief Translates an SDL resize request.
     * @param sdlEvent to translate.
     * @returns The translated event.
     */
#if defined(SDL_BACKEND)
	static Resize translateEvent(SDL_WindowEvent &sdlEvent);
#endif //SDL_BACKEND
};

}

#endif // RESIZE_HPP
