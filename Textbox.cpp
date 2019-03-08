#include "Textbox.hpp"

namespace ui
{
	Textbox::Textbox()
	{
		this->isSelected = false;
		this->type = elementType_t::TEXTBOX;
	}

	void Textbox::setTexture(const sf::Texture& texture)
	{
		this->texture = texture;
		this->sprite.setTexture(this->texture);
	}

	void Textbox::setRect(const sf::Vector2f& position, const sf::Vector2f& size)
	{
		this->position = position;
		this->size = size;
		this->sprite.setPosition(this->position);
		this->sprite.setScale({ this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y });

		this->text.setPosition({ this->position.x + 5.f, this->position.y + (this->size.y / 2.f) - 5.f });
	}

	void Textbox::setTextFont(const sf::Font& font)
	{
		this->text.setFont(font);
	}

	void Textbox::setTextColor(const sf::Color color)
	{
		this->text.setFillColor(color);
	}

	void Textbox::setTextSize(unsigned size)
	{
		this->text.setCharacterSize(size);
	}

	// Virtual methods

	void Textbox::use(sf::Event& event)
	{
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			if (this->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
				this->isSelected = true;
			else
				this->isSelected = false;
		}

		if (this->isSelected)
		{

			if (event.key.code == sf::Keyboard::BackSpace)
			{
				if (this->text.getString().getSize() > 0)
				{
					this->text.setString(this->text.getString().substring(0, this->text.getString().getSize() - 2));
				}
			}
			else if (event.key.code == sf::Keyboard::Return)
			{
				this->isSelected = false;
			}
			else if (event.type == sf::Event::TextEntered)
			{
				if((event.text.unicode >= 48 && event.text.unicode <= 57) ||
				(event.text.unicode >= 65 && event.text.unicode <= 90) ||
				(event.text.unicode >= 97 && event.text.unicode <= 122))
				{
					if (this->text.getString().getSize() < this->size.x / this->text.getCharacterSize())
					{
						this->text.setString(this->text.getString() + static_cast<char>(event.text.unicode));
					}
				}
			}
		}
	}

	void Textbox::update(sf::RenderWindow& window)
	{
		window.draw(this->sprite);
		window.draw(this->text);
	}
}