#include <SFML/Graphics.hpp>
#include <regex>
import GraphicElement;

export module UI_mod;

export class UI : public GraphicElement
{
public:
	UI(sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer, bool _rightSideOrigin = false)
	{
		m_layer = _layer;
		//Transform	
		m_objSize = _objSize;
		if (!_rightSideOrigin)setOrigin(m_objSize.x / 2, m_objSize.y / 2);
		else setOrigin(0, m_objSize.y / 2);
		setPosition(_position);

		//VertexArray
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(4);
		m_vertices[0].position = sf::Vector2f(0, 0);
		m_vertices[1].position = sf::Vector2f(0 + m_objSize.x, 0);
		m_vertices[2].position = sf::Vector2f(0 + m_objSize.x, 0 + m_objSize.y);
		m_vertices[3].position = sf::Vector2f(0, 0 + m_objSize.y);

		//Texture
		m_texture = _texture;
		m_vertices[0].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top);
		m_vertices[1].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top);
		m_vertices[2].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top + _textureStart.height);
		m_vertices[3].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top + _textureStart.height);
	}
	~UI()
	{

	}
	virtual int whatLayer()
	{
		return m_layer;
	}
	virtual std::string GetType()
	{
		return "UI";
	}
	virtual void ChangeTextuerCords(sf::IntRect _textureStart)
	{
		m_vertices[0].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top);
		m_vertices[1].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top);
		m_vertices[2].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top + _textureStart.height);
		m_vertices[3].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top + _textureStart.height);
	}
	void ChangeRightSize(float _size)
	{
		if (_size < 0)_size = 0;
		m_objSize.x = _size;
		m_vertices[1].position = sf::Vector2f(0 + m_objSize.x, 0);
		m_vertices[2].position = sf::Vector2f(0 + m_objSize.x, 0 + m_objSize.y);
	}
protected:
	sf::Vector2f m_objSize;
	sf::VertexArray m_vertices;
	sf::Texture m_texture;
	int m_layer = 0;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_texture;
		target.draw(m_vertices, states);
	}
};

export class TextFieldUI : public UI
{
public:
	TextFieldUI(std::string _text, sf::Font& _font, int _fontSize, sf::Color  _fontColor, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer, bool _draw_BG = true)
		:UI(_texture, _textureStart, _position, _objSize, _layer), draw_BG(_draw_BG)
	{

		m_text = sf::Text(_text, _font, _fontSize);
		m_text.setFillColor(_fontColor);
		//WŒRODKOWAÆ TEKST ROSKMIÑ

		m_text.setOrigin(m_text.getLocalBounds().width / 2, _objSize.y / 2 - (_objSize.y - m_text.getLocalBounds().height) / 4);
		m_text.setOrigin(this->getOrigin());
		m_text.setPosition(_objSize.x / 2, _objSize.y / 2);
		//m_text.setPosition(m_text.getLocalBounds().width / 2, _objSize.y/2);
		/*statesText.transform = m_text.getTransform();*/
		//TO DO
		//ZAWIJANIE TEKSTU TO MATCH FIELD

	}
	virtual std::string GetType()
	{
		return "TextFieldUI";
	}
	void SetString(std::string _text)
	{
		_text = std::regex_replace(_text, std::regex("\\$n"), "\n");
		m_text.setString(_text);
	}
protected:
	sf::Text m_text;
	bool draw_BG;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_texture;
		if (draw_BG)target.draw(m_vertices, states);
		target.draw(m_text, states);
	}
};