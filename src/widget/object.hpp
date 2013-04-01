#ifndef _SALMON_OBJECT_HPP_
#define _SALMON_OBJECT_HPP_

#include <stdint.h>
#include "../gom/rect.hpp"

namespace salmon {
	class object : public rect<int>
	{
	private:
		uint32_t id;
		void remove_child();

	public:

		virtual void add(object *child);
		virtual void remove();
	};
}

#endif // _SALMON_OBJECT_HPP_
