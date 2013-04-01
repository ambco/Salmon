#include <iostream>

#include "gom/location.hpp"
#include "gom/size.hpp"
#include "gom/rect.hpp"

int main()
{
	Salmon::Location<int> loc(1, 2);
	std::cout << loc.getX() << " " << loc.getY() << std::endl;
	Salmon::Location<int> loc1(Salmon::Location<int>(3, 4));
	std::cout << loc1.getX() << " " << loc1.getY() << std::endl;
	loc.setLocation(Salmon::Location<int>(8, 8));
	std::cout << loc.getX() << " " << loc.getY() << std::endl;

	Salmon::Size<int> s(1, 2);
	std::cout << s.getW() << " " << s.getW() << std::endl;
	Salmon::Size<int> s1(Salmon::Size<int>(3, 4));
	std::cout << s1.getW() << " " << s1.getH() << std::endl;
	s.setSize(Salmon::Size<int>(8, 8));
	std::cout << s.getW() << " " << s.getW() << std::endl;

	Salmon::Rect<int> r(Salmon::Location<int>(10, 10),
	                    Salmon::Size<int>(12, 12));

	return 0;
}
