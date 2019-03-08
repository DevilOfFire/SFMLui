#include "Element.hpp"

namespace ui
{
	// Public

	void Element::update( sf::RenderWindow& window )
	{
		window.draw( this->sprite );
	}
}