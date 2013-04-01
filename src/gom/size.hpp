#ifndef _SALMON_SIZE_HPP_
#define _SALMON_SIZE_HPP_

namespace Salmon {
	template <class T>
	struct Size_t {
		T w;
		T h;
	};

	/** A size with a width and height.
	 */
	template <class T>
	class Size
	{
	private:
		T w; /**< Width. */
		T h; /**< height. */

	public:
		/** Sets size.
		 *
		 * \param w width.
		 * \param h height.
		 */
		Size(T w, T h) : w(w), h(h)
		{}

		Size(const Size<T> &s) : Size(s.getW(),
		                              s.getW())
		{}

		Size() : Size(100, 100)
		{}

		virtual void setW(T w)
		{
			setSize(w, this->h);
		}

		virtual void setH(T h)
		{
			setSize(this->w, h);
		}

		virtual void setSize(T w, T h)
		{
			setSize(Size<T>(w, h));
		}

		virtual void setSize(const Size<T> &s)
		{
			w = s.getW();
			h = s.getH();
		}

		virtual Size<T> getSize() const
		{
			return Size<T>(w, h);
		}

		virtual T getW() const
		{
			return getSize().w;
		}

		virtual T getH() const
		{
			return getSize().h;
		}
	};
}

#endif //_SALMON_SIZE_HPP_
