/*
* Implementation of Menu class
*/

#include <cmath>
#include "GameManager.h"
#include <iostream>
#include "Menu.h"
#include <thread>

Menu::Menu() :
	Actor(),
	_outlineThickness(3),
	_outlineColor(204, 204, 204),
	_color(59, 66, 79),
	_padding(10),
	_currentSelectionIdx(0)
{
	_menuCanvas.setFillColor(_color);
	_menuCanvas.setOutlineColor(_outlineColor);
	_menuCanvas.setOutlineThickness(_outlineThickness);

	// Load sound from file
	if (!_selectionChangeSoundBuffer.loadFromFile("Resources/MenuSelectionChange.wav"))
	{
		std::cerr << "Error: Could not load audio from file.";
	}
	else
	{
		_selectionChangeSound.setBuffer(_selectionChangeSoundBuffer);
	}

	if (!_selectSoundBuffer.loadFromFile("Resources/MenuSelect.wav"))
	{
		std::cerr << "Error: Could not load audio from file.";
	}
	else
	{
		_selectSound.setBuffer(_selectSoundBuffer);
	}
}

Menu::~Menu()
{
	for (auto &item : _items)
	{
		if (item) delete item;
		item = nullptr;
	}
}

void Menu::Draw(sf::RenderWindow &window)
{
	window.draw(_menuCanvas);

	unsigned count = 0;
	for (MenuItem *item : _items)
	{
		item->SetPosition(_menuCanvas.getPosition().x + _padding, (_menuCanvas.getPosition().y + _padding) + (item->GetDimensions().y + _padding) * count++);
		item->Draw(window);
	}
}

void Menu::SetPosition(const float &xPosition, const float &yPosition)
{
	Actor::SetPosition(xPosition, yPosition);
	_menuCanvas.setPosition(_position);
}

void Menu::UpdateCanvas()
{
	// Create a rectangle
	_menuCanvas.setPointCount(4);
	_menuCanvas.setPoint(0, sf::Vector2f(0, 0));
	_menuCanvas.setPoint(1, sf::Vector2f(0, _dimensions.y));
	_menuCanvas.setPoint(2, sf::Vector2f(_dimensions.x, _dimensions.y));
	_menuCanvas.setPoint(3, sf::Vector2f(_dimensions.x, 0));
}

void Menu::AddMenuItem(MenuItem *item)
{
	_items.push_back(item);
	_dimensions.y += item->GetDimensions().y + _padding * 2;
	_dimensions.x = std::max(_dimensions.x, item->GetDimensions().x + _padding * 3);

	if (!_items[0]->IsSelected()) _items[0]->ToggleSelected();

	UpdateCanvas();
}

void Menu::MoveUp()
{
	if (_currentSelectionIdx != 0)
	{
		_items[_currentSelectionIdx--]->ToggleSelected();
		_items[_currentSelectionIdx]->ToggleSelected();
		if (GameManager::GetInstance().IsAudioEnabled()) _selectionChangeSound.play();
	}
}

void Menu::MoveDown()
{
	if (_currentSelectionIdx != _items.size() - 1)
	{
		_items[_currentSelectionIdx++]->ToggleSelected();
		_items[_currentSelectionIdx]->ToggleSelected();
		if (GameManager::GetInstance().IsAudioEnabled()) _selectionChangeSound.play();
	}
}

std::string Menu::GetSelection()
{
	if (GameManager::GetInstance().IsAudioEnabled()) _selectSound.play();

	while (_selectSound.getStatus() == sf::Sound::Playing)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return _items[_currentSelectionIdx]->GetText();
}