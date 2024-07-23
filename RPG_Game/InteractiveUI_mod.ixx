#include <SFML/Graphics.hpp>
import GraphicElement;
import UI_mod;

export module InteractiveUI_mod;

export class InteractiveUI : public UI
{
public:
	InteractiveUI(sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
		:UI(_texture, _textureStart, _position, _objSize, _layer)
	{
	}
	virtual bool IsMouseOn(sf::Vector2i _mouse)
	{
		sf::FloatRect t_FloatRect = m_vertices.getBounds();
		t_FloatRect.left = getPosition().x - (m_objSize.x * getScale().x) / 2;
		t_FloatRect.top = getPosition().y - (m_objSize.y * getScale().y) / 2;
		t_FloatRect.width *= getScale().x;
		t_FloatRect.height *= getScale().y;
		if (t_FloatRect.contains(_mouse.x, _mouse.y))return true;
		else return false;
	}
	virtual void SetUIColor(sf::Color _color)
	{
		m_vertices[0].color = _color;
		m_vertices[1].color = _color;
		m_vertices[2].color = _color;
		m_vertices[3].color = _color;
	}
	virtual void SetDefaultUIColor()
	{
		m_vertices[0].color = sf::Color(255, 255, 255, 255);
		m_vertices[1].color = sf::Color(255, 255, 255, 255);
		m_vertices[2].color = sf::Color(255, 255, 255, 255);
		m_vertices[3].color = sf::Color(255, 255, 255, 255);
	}
	virtual void SetPressed()
	{
		isPressed = true;
	}
	virtual void UnSetPressed()
	{
		isPressed = false;
	}
	virtual bool IsUIPressed()
	{
		return isPressed;
	}
	virtual std::string GetType()
	{
		return "InteractiveUI";
	}
	~InteractiveUI()
	{

	}
protected:
	bool isPressed = false;
private:
};

export class HoverAndPressedUI : public InteractiveUI
{
public:
	HoverAndPressedUI(bool& _toSet, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
	{
		toSet = std::unique_ptr<bool>(&_toSet);
		*toSet = false;
	}
	void ActiveAction()
	{
		*toSet = true;
	}
	bool ActionStatus()
	{
		return *toSet;
	}
	virtual std::string GetType()
	{
		return "HoverAndPressedUI";
	}
	~HoverAndPressedUI()
	{
		toSet.release();
	}
protected:
private:
	std::unique_ptr<bool> toSet;
};

export class ChooseFromSetUI : public InteractiveUI
{
public:
	ChooseFromSetUI(int _value, int _setNumber, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
	{
		value = _value;
		setNumber = _setNumber;
	}

	virtual std::string GetType()
	{
		return "ChooseFromSetUI";
	}
	int GetValue()
	{
		return value;
	}
	void SetValue(int _value)
	{
		value = _value;
	}
	int GetSetNumber()
	{
		return setNumber;
	}
	void SetSetNumber(int _setNumber)
	{
		setNumber = _setNumber;
	}
protected:
private:
	int value = 0;
	int setNumber = 0;
};

export class MoveableUI : public InteractiveUI
{
public:
	MoveableUI(int _slotnumber, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
	{
		slotnumber = _slotnumber;
		positionToBack = _position;
	}
	virtual std::string GetType()
	{
		return "MoveableUI";
	}
	int GetSlotNumber()
	{
		return slotnumber;
	}
	void setAttached()
	{
		attached = true;
	}
	void setUnAttached()
	{
		attached = false;
	}
	bool GetAttached()
	{
		return attached;
	}
	void SetActive()
	{
		active = true;
	}
	void SetUnActive()
	{
		active = false;
	}
	bool GetActive()
	{
		return active;
	}
	void BackToPosition()
	{
		setPosition(positionToBack);
	}
	void SetBackPosition(sf::Vector2f _positionToBack)
	{
		positionToBack = _positionToBack;
	}
protected:
	bool attached = false;
	bool active = false;
	int slotnumber;
	sf::Vector2f positionToBack;
private:
};

export class SlotForMUI : public InteractiveUI
{
public:
	SlotForMUI(int _slotNumber, int _setNumber, std::string _type, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
	{
		slotnumber = _slotNumber;
		setNumber = _setNumber;
		type = _type;
	}
	virtual std::string GetType()
	{
		return "SlotForMUI";
	}
	int GetSlotNumber()
	{
		return slotnumber;
	}
	std::string GetSlotType()
	{
		return type;
	}
	void SetSlotNumber(int _slotNumber)
	{
		slotnumber = _slotNumber;
	}
	int GetSetNumber()
	{
		return setNumber;
	}
	void SetSetNumber(int _setNumber)
	{
		setNumber = _setNumber;
	}
	bool GetFull()
	{
		return full;
	}
	void SetFull()
	{
		full = true;
	}
	void UnSetFull()
	{
		full = false;
	}
protected:
	bool full = false;
	int setNumber = 0;
	int slotnumber = 0;
	std::string type = "All";
private:
};

export class TextBoxUI : public InteractiveUI
{
public:
	TextBoxUI(sf::Font& _font, int _fontSize, sf::Color  _fontColor, int _letterLimit, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
	{
		m_text = sf::Text("", _font, _fontSize);
		m_text.setFillColor(_fontColor);
		m_letterLimit = _letterLimit;
	}
	void WriteChar(char _letter)
	{
		if (m_str.size() < m_letterLimit)
		{
			m_str += _letter;
			if (writeHidden)m_text.setString(m_text.getString() + '*');
			else m_text.setString(m_str);

		}


	}
	void RemoveLetter()
	{
		if (m_str.size() != 0)
		{
			m_str.pop_back();
			if (writeHidden)
			{
				std::string tmp = m_text.getString();
				tmp.pop_back();
				m_text.setString(tmp);
			}
			else m_text.setString(m_str);
		}
	}
	void ResetText()
	{
		m_str = "";
		m_text.setString(m_str);
	};
	void setHidden(bool _hidden)
	{
		writeHidden = _hidden;
	}
	virtual std::string GetType()
	{
		return "TextBoxUI";
	}
	bool IsHidden()
	{
		return writeHidden;
	}
	std::string GetString()
	{
		return m_str;
	}
protected:
	sf::Text m_text;
	std::string m_str;
	int m_letterLimit;
	bool writeHidden = false;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_texture;
		target.draw(m_vertices, states);
		states.texture = NULL;
		target.draw(m_text, states);
	}
};