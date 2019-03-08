#include "ui\UI.hpp"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
	sf::Texture texture, textureOff, textureOn;
	sf::Font font;
	sf::Text text;
	sf::RectangleShape shape;
	shape.setFillColor(sf::Color::White);
	shape.setSize({ 200.f, 100.f });
	text.setFont(font);
	text.setString("Lorem Ipsum");
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(10);

	texture.loadFromFile("cute_image.jpg");
	// return EXIT_FAILURE;
	textureOff.loadFromFile("cute_image.jpg");
	//	return EXIT_FAILURE;
	textureOn.loadFromFile("cute.jpg");
	//	return EXIT_FAILURE;
	font.loadFromFile("arial.ttf");
	//	return EXIT_FAILURE;
	ui::UI userInterface(window);

	// Button
	ui::Button *button = userInterface.add<ui::Button>();
	button->setTexture(texture, textureOn);
	button->setPosition({ 400.f, 0 });
	button->setSize({ userInterface.getPercent(50.f, userInterface.getWindowSize().x), 200.f });
	button->addCallback([]()->void {
		MessageBoxA(NULL, "Hello", "Error", MB_OK);
	});

	// Checkbox
	ui::Checkbox *checkbox = userInterface.add<ui::Checkbox>();
	checkbox->setEnable(true);
	checkbox->setTexture(textureOff, textureOn);
	checkbox->setPosition({ 500.f, 500.f });
	checkbox->setSize({ 100.f, 100.f });
	checkbox->addCallbackOff([]()->void {
		MessageBoxA(NULL, "Off", "Off", MB_OK);
	});
	checkbox->addCallbackOn([]()->void {
		MessageBoxA(NULL, "On", "On", MB_OK);
	});

	// Slider
	ui::Slider *slider = userInterface.add<ui::Slider>();
	slider->setTexture(textureOff, textureOn);
	slider->setRect({ 200.f, 300.f }, { 400.f, 50.f });
	slider->setCheckingInRealMode(false);
	slider->addCallback([](ui::Slider* slider)->void {
		sf::Texture textureOne, textureTwo;
		textureOne.loadFromFile("cute.jpg");
		textureTwo.loadFromFile("cute_image.jpg");
		if (slider->scalePositionOfRateToReal(100.f) >= 50)
			MessageBoxA(NULL, "Odlkik³eœ na drugiej po³owie paska od lewej!", "Powiadomienie", MB_OK);
		else
			MessageBoxA(NULL, "Odlkik³eœ na pierwszej po³owie paska od lewej!", "Powiadomienie", MB_OK);

	});

	// List
	ui::List *list = userInterface.add<ui::List>();
	list->setTexture(textureOff);
	list->setRect({ 0,0 }, { 100.f,50.f });
	list->setDescription(shape, 1000.f);
	list->addElement([]()->void {
		MessageBoxA(NULL, "Hello", "Error", MB_OK);
	}, textureOn, text);
	list->addElement([]()->void {
		MessageBoxA(NULL, "Hello", "Error", MB_OK);
	}, textureOff, text);

	// Textbox
	ui::Textbox *textbox = userInterface.add<ui::Textbox>();
	textbox->setTexture(textureOff);
	textbox->setRect({ 50.f,50.f }, { 100.f,100.f });
	textbox->setTextFont(font);
	textbox->setTextColor(sf::Color::White);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			userInterface.useButtons(event);
			userInterface.useCheckboxs(event);
			userInterface.useSliders(event);
			userInterface.useLists(event);
			userInterface.useTextbox(event);
		}

		window.clear();
		userInterface.updateButtons(window);
		userInterface.updateCheckboxs(window);
		userInterface.updateSliders(window);
		userInterface.updateLists(window);
		userInterface.updateTextbox(window);
		window.display();
	}
	return EXIT_SUCCESS;
}