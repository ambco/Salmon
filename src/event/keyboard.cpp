#include "keyboard.hpp"
#include <functional>

namespace Salmon
{
	Keyboard::Keyboard()
	{}

 	Keyboard::Keyboard(Code code) :
		code(code)
	{}

	Keyboard::Keyboard(Code code,
	                   bool alt,
	                   bool ctrl,
	                   bool system) :
		code(code),
		alt(alt),
		ctrl(ctrl),
		system(system)
	{}

#if defined(SDL_BACKEND)
	Keyboard Keyboard::TranslateEvent(SDL_KeyboardEvent &sdlEvent)
	{
		auto check_mod = [] (Uint16 mod, Uint16 check) {
			if ((mod & check) == check)
				return true;
			return false;
		};

		Keyboard ev;

		Uint16 mod_key = sdlEvent.keysym.mod;

		ev.alt = check_mod(mod_key, KMOD_ALT);
		ev.ctrl = check_mod(mod_key, KMOD_CTRL);
		ev.system = check_mod(mod_key, KMOD_GUI);

		switch(sdlEvent.keysym.sym) {
		case SDLK_0:         ev.code = num0; break;
		case SDLK_1:         ev.code = num1; break;
		case SDLK_2:         ev.code = num2; break;
		case SDLK_3:         ev.code = num3; break;
		case SDLK_4:         ev.code = num4; break;
		case SDLK_5:         ev.code = num5; break;
		case SDLK_6:         ev.code = num6; break;
		case SDLK_7:         ev.code = num7; break;
		case SDLK_8:         ev.code = num8; break;
		case SDLK_9:         ev.code = num9; break;
		case SDLK_a:         ev.code = a; break;
		case SDLK_b:         ev.code = b; break;
		case SDLK_c:         ev.code = c; break;
		case SDLK_d:         ev.code = d; break;
		case SDLK_e:         ev.code = e; break;
		case SDLK_f:         ev.code = f; break;
		case SDLK_g:         ev.code = g; break;
		case SDLK_h:         ev.code = h; break;
		case SDLK_i:         ev.code = i; break;
		case SDLK_j:         ev.code = j; break;
		case SDLK_k:         ev.code = k; break;
		case SDLK_l:         ev.code = l; break;
		case SDLK_m:         ev.code = m; break;
		case SDLK_n:         ev.code = n; break;
		case SDLK_o:         ev.code = o; break;
		case SDLK_p:         ev.code = p; break;
		case SDLK_q:         ev.code = q; break;
		case SDLK_r:         ev.code = r; break;
		case SDLK_s:         ev.code = s; break;
		case SDLK_t:         ev.code = t; break;
		case SDLK_u:         ev.code = u; break;
		case SDLK_v:         ev.code = v; break;
		case SDLK_w:         ev.code = w; break;
		case SDLK_x:         ev.code = x; break;
		case SDLK_y:         ev.code = y; break;
		case SDLK_z:         ev.code = z; break;
		case SDLK_BACKSPACE: ev.code = backspace; break;
		case SDLK_SPACE:     ev.code = space; break;
		case SDLK_RETURN:    ev.code = enter; break;
		case SDLK_LCTRL:     ev.code = lctrl; break;
		case SDLK_RCTRL:     ev.code = rctrl; break;
		case SDLK_LSHIFT:    ev.code = lshift; break;
		case SDLK_RSHIFT:    ev.code = rshift; break;
		case SDLK_TAB:       ev.code = tab; break;
		case SDLK_ESCAPE:    ev.code = escape; break;
		case SDLK_CAPSLOCK:  ev.code = capslock; break;
		case SDLK_PERIOD:    ev.code = period; break;
		case SDLK_COMMA:     ev.code = comma; break;
		case SDLK_SEMICOLON: ev.code = semicolon; break;
		case SDLK_LGUI:      ev.code = lsystem; break;
		case SDLK_RGUI:      ev.code = rsystem; break;
		case SDLK_LALT:      ev.code = lalt; break;
		case SDLK_RALT:      ev.code = ralt; break;
		case SDLK_F1:        ev.code = F1; break;
		case SDLK_F2:        ev.code = F2; break;
		case SDLK_F3:        ev.code = F3; break;
		case SDLK_F4:        ev.code = F4; break;
		case SDLK_F5:        ev.code = F5; break;
		case SDLK_F6:        ev.code = F6; break;
		case SDLK_F7:        ev.code = F7; break;
		case SDLK_F8:        ev.code = F8; break;
		case SDLK_F9:        ev.code = F9; break;
		case SDLK_F10:       ev.code = F10; break;
		case SDLK_F11:       ev.code = F11; break;
		case SDLK_F12:       ev.code = F12; break;
		case SDLK_DOWN:      ev.code = down; break;
		case SDLK_UP:        ev.code = up; break;
		case SDLK_LEFT:      ev.code = left; break;
		case SDLK_RIGHT:     ev.code = right; break;
		default:             ev.code = unknown; break;
		}

		return ev;
	}
#endif //defined(SDL_BACKEND)
}
