#ifndef SALMON_EVENT_HPP_
#define SALMON_EVENT_HPP_

namespace Salmon
{

/**
 * @brief Class handeling event structures.
 *
 * It is used to send all different kind of events to a specific function
 * to then dispach events correctly.
 */
class Event
{
public:

    /**
     * @brief All different kinds of event.
     *
     * All event types don't have an associated data structure.
     */
    enum Type {
        lostFocus, /**< Object lost focus. */
        gainedFocus, /**< Object gained focus. */
        enter, /**< Mouse enters object. */
        leave, /**< Mouse leaves object. */
        closed, /**< Window closed. */
        mouseButtonPressed, /**< Mouse button pressed. */
        mouseButtonReleased, /**< Mouse button released. */
        mouseMoved, /**< Mouse moved. */
        keyPressed, /**< Keyboard key pressed. */
        keyReleased, /**< Keyboard key released. */
        redraw, /**< Object has to redraw. */
        resize, /**< Resize event. */
        move, /**< Object moved. */
        unknown /**< All other not recognized events. */
    };

    Type type; /**< The type of event happened. */
};

}

#endif
