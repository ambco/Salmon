#ifndef _SALMON_LOCATION_HPP_
#define _SALMON_LOCATION_HPP_

namespace Salmon {

	template <class T>
	struct Location_t {
		T x;
		T y;
	};

	/** A location on an xy-plane.
	 */
	template <class T>
	class Location
	{
	private:
		T x; /**< Location on the x-axis. */
		T y; /**< Location on the y-axis. */

	public:
		/** Sets location in the constructor.
		 *
		 * \param x location.
		 * \param y location.
		 */
		Location(T x, T y) : x(x), y(y)
		{}

		/** Sets location in the constructor.
		 *
		 * \param loc the location to be set.
		 */
		Location(const Location<T> &loc) : Location(loc.getX(),
		                                            loc.getY())
		{}

		/** Sets default location of 0, 0 in constructor.
		 */
		Location() : Location(0, 0)
		{}

		/** Sets x location.
		 *
		 * \param x location.
		 */
		virtual void setX(T x)
		{
			setLocation(x, this->y);
		}

		/** Sets y location.
		 *
		 * \param y location.
		 */
		virtual void setY(T y)
		{
			setLocation(this->x, y);
		}

		/** Sets new location.
		 *
		 * \param loc new location.
		 */
		virtual void setLocation(const Location<T> &loc)
		{
			x = loc.getX();
			y = loc.getY();
		}

		/** Sets new location.
		 *
		 * \param x new location.
		 * \param y new location.
		 */
		virtual void setLocation(T x, T y)
		{
			setLocation(Location<T>(x, y));
		}

		/** Queries for the location.
		 *
		 * \returns current location.
		 */
		virtual Location<T> getLocation() const
		{
			return Location<T>(x, y);
		}

		/** Queries for the location on x.
		 *
		 * \returns current location on x.
		 */
		virtual T getX() const
		{
			return getLocation().x;
		}

		/** Queries for the location on y.
		 *
		 * \returns current location on y.
		 */
		virtual T getY() const
		{
			return getLocation().y;
		}
	};
}

#endif
