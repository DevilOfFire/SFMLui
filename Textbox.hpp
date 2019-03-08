/*
===============================================================================
Created by: Beniamin Gajecki ,,Uriel"
Textbox class.
===============================================================================
*/
#pragma once

#include "Element.hpp"

namespace ui
{
	class Textbox final : public Element
	{
	public:
		Textbox();
		~Textbox() = default;

		// VIEW FUNCTIONS START
		// Set textbox texture
		void setTexture(const sf::Texture&);
		// Set textbox postition and size
		void setRect(const sf::Vector2f&, const sf::Vector2f&);
		// Set textbox text font
		void setTextFont(const sf::Font&);
		// Set textbox text color
		void setTextColor(const sf::Color);
		// Set textbox text size
		void setTextSize(unsigned);
		// VIEW FUNCTIONS END

		// GET START
		// Get textbox texture
		const sf::Texture getTexture() const { return this->texture; }
		// Get textbox text
		const sf::Text getText() const { return this->text; }
		// GET END

	private:
		sf::Texture texture;
		sf::Text text;
		bool isSelected;

		// VIRTUAL FUNCTIONS START
		void use(sf::Event&) final;
		void update(sf::RenderWindow&) final;
		// VIRTUAL FUNCTIONS START
	};
}