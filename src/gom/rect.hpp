#ifndef _SALMON_RECT_HPP_
#define _SALMON_RECT_HPP_

#include "location.hpp"
#include "size.hpp"

namespace Salmon {
	template <class T>
	struct Rect_t {
		Location_t<T> location;
		Size_t<T> size;
	};

	template <class T>
	class Rect : public Location<T>, public Size<T>
	{
	public:
		Rect(T x, T y, T w, T h) :
			Location<T>::Location(x, y),
			Size<T>::Size(w, h)
		{}

		Rect(const Location<T> &loc, const Size<T> &s) :
			Location<T>::Location(loc),
			Size<T>::Size(s)
		{}

		Rect() :
			Location<T>::Location(),
			Size<T>::Size()
		{}

		virtual void setRect(const Rect<T> &r)
		{
			this->setLocation(r.getX(), r.getY());
			this->setSize(r.getW(), r.getH());
		}

		virtual void setRect(T x, T y, T w, T h)
		{
			setRect(Rect<T>(x, y, w, h));
		}

		virtual Rect<T> getRect() const
		{
			return Rect<T>(this->getLocation(), this->getSize());
		}
	};
}

#endif // _SALMON_RECT_HPP_
