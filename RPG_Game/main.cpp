#include <SFML/Graphics.hpp>
#include <regex>
#include <ranges>
#include <filesystem>
#include "Data_base.h"
#include "Fight.h"

import GraphicElement;
import UI_mod;
import InteractiveUI_mod;

//class GraphicElement : public sf::Drawable, public sf::Transformable
//{
//public:
//protected:
//private:
//    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
//};

//UI CLASSES
//class UI : public GraphicElement
//{
//public:
//	UI(sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize,int _layer, bool _rightSideOrigin=false)
//	{
//		m_layer = _layer;
//		//Transform	
//		m_objSize = _objSize;
//		if (!_rightSideOrigin)setOrigin(m_objSize.x / 2, m_objSize.y / 2);
//		else setOrigin(0, m_objSize.y / 2);
//		setPosition(_position);
//
//		//VertexArray
//		m_vertices.setPrimitiveType(sf::Quads);
//		m_vertices.resize(4);
//		m_vertices[0].position = sf::Vector2f(0, 0);
//		m_vertices[1].position = sf::Vector2f(0 + m_objSize.x, 0);
//		m_vertices[2].position = sf::Vector2f(0 + m_objSize.x, 0 + m_objSize.y);
//		m_vertices[3].position = sf::Vector2f(0, 0 + m_objSize.y);
//
//		//Texture
//		m_texture = _texture;
//		m_vertices[0].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top);
//		m_vertices[1].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top);
//		m_vertices[2].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top + _textureStart.height);
//		m_vertices[3].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top + _textureStart.height);
//	}
//	~UI()
//	{
//
//	}
//	virtual int whatLayer()
//	{
//		return m_layer;
//	}
//	virtual std::string GetType()
//	{
//		return "UI";
//	}
//	virtual void ChangeTextuerCords(sf::IntRect _textureStart)
//	{
//		m_vertices[0].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top);
//		m_vertices[1].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top);
//		m_vertices[2].texCoords = sf::Vector2f(_textureStart.left + _textureStart.width, _textureStart.top + _textureStart.height);
//		m_vertices[3].texCoords = sf::Vector2f(_textureStart.left, _textureStart.top + _textureStart.height);
//	}
//	void ChangeRightSize(float _size)
//	{
//		if (_size < 0)_size = 0;
//		m_objSize.x = _size;
//		m_vertices[1].position = sf::Vector2f(0 + m_objSize.x, 0);
//		m_vertices[2].position = sf::Vector2f(0 + m_objSize.x, 0 + m_objSize.y);
//	}
//protected:
//	sf::Vector2f m_objSize;
//	sf::VertexArray m_vertices;
//	sf::Texture m_texture;
//	int m_layer=0;
//private:
//	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
//	{
//		states.transform *= getTransform();
//		states.texture = &m_texture;
//		target.draw(m_vertices, states);
//	}
//};
//
//class InteractiveUI : public UI
//{
//public:
//	InteractiveUI(sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
//		:UI(_texture, _textureStart, _position, _objSize, _layer)
//	{
//	}
//	virtual bool IsMouseOn(sf::Vector2i _mouse)
//	{
//		sf::FloatRect t_FloatRect = m_vertices.getBounds();
//		t_FloatRect.left = getPosition().x - (m_objSize.x * getScale().x) / 2;
//		t_FloatRect.top = getPosition().y - (m_objSize.y * getScale().y) / 2;
//		t_FloatRect.width *= getScale().x;
//		t_FloatRect.height *= getScale().y;
//		if (t_FloatRect.contains(_mouse.x, _mouse.y))return true;
//		else return false;
//	}
//	virtual void SetUIColor(sf::Color _color)
//	{
//		m_vertices[0].color = _color;
//		m_vertices[1].color = _color;
//		m_vertices[2].color = _color;
//		m_vertices[3].color = _color;
//	}
//	virtual void SetDefaultUIColor()
//	{
//		m_vertices[0].color = sf::Color(255, 255, 255, 255);
//		m_vertices[1].color = sf::Color(255, 255, 255, 255);
//		m_vertices[2].color = sf::Color(255, 255, 255, 255);
//		m_vertices[3].color = sf::Color(255, 255, 255, 255);
//	}
//	virtual void SetPressed()
//	{
//		isPressed = true;
//	}
//	virtual void UnSetPressed()
//	{
//		isPressed = false;
//	}
//	virtual bool IsUIPressed()
//	{
//		return isPressed;
//	}
//	virtual std::string GetType()
//	{
//		return "InteractiveUI";
//	}
//	~InteractiveUI()
//	{
//
//	}
//protected:
//	bool isPressed = false;
//private:
//};
//
//class HoverAndPressedUI : public InteractiveUI
//{
//public:
//	HoverAndPressedUI(bool& _toSet, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
//		:InteractiveUI(_texture, _textureStart, _position, _objSize,_layer)
//	{
//		toSet = std::unique_ptr<bool>(&_toSet);
//		*toSet = false;
//	}
//	void ActiveAction()
//	{
//		*toSet = true;
//	}
//	bool ActionStatus()
//	{
//		return *toSet;
//	}
//	virtual std::string GetType()
//	{
//		return "HoverAndPressedUI";
//	}
//	~HoverAndPressedUI()
//	{
//		toSet.release();
//	}
//protected:
//private:
//	std::unique_ptr<bool> toSet;
//};
//class ChooseFromSetUI : public InteractiveUI
//{
//public:
//	ChooseFromSetUI(int _value,int _setNumber, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
//		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
//	{
//		value = _value;
//		setNumber = _setNumber;
//	}
//
//	virtual std::string GetType()
//	{
//		return "ChooseFromSetUI";
//	}
//	int GetValue()
//	{
//		return value;
//	}
//	void SetValue(int _value)
//	{
//		value = _value;
//	}
//	int GetSetNumber()
//	{
//		return setNumber;
//	}
//	void SetSetNumber(int _setNumber)
//	{
//		setNumber = _setNumber;
//	}
//protected:
//private:
//	int value=0;
//	int setNumber = 0;
//};
//
//class MoveableUI : public InteractiveUI
//{
//public:
//	MoveableUI(int _slotnumber, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
//		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
//	{
//		slotnumber = _slotnumber;
//		positionToBack = _position;
//	}
//	virtual std::string GetType()
//	{
//		return "MoveableUI";
//	}
//	int GetSlotNumber()
//	{
//		return slotnumber;
//	}
//	void setAttached()
//	{
//		attached = true;
//	}
//	void setUnAttached()
//	{
//		attached = false;
//	}
//	bool GetAttached()
//	{
//		return attached;
//	}
//	void SetActive()
//	{
//		active = true;
//	}
//	void SetUnActive()
//	{
//		active = false;
//	}
//	bool GetActive()
//	{
//		return active;
//	}
//	void BackToPosition()
//	{
//		setPosition(positionToBack);
//	}
//	void SetBackPosition(sf::Vector2f _positionToBack)
//	{
//		positionToBack = _positionToBack;
//	}
//protected:
//	bool attached =false;
//	bool active = false;
//	int slotnumber;
//	sf::Vector2f positionToBack;
//private:
//};
//class SlotForMUI : public InteractiveUI
//{
//public:
//	SlotForMUI(int _slotNumber, int _setNumber,std::string _type, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
//		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
//	{
//		slotnumber = _slotNumber;
//		setNumber = _setNumber;
//		type = _type;
//	}
//	virtual std::string GetType()
//	{
//		return "SlotForMUI";
//	}
//	int GetSlotNumber()
//	{
//		return slotnumber;
//	}
//	std::string GetSlotType()
//	{
//		return type;
//	}
//	void SetSlotNumber(int _slotNumber)
//	{
//		slotnumber = _slotNumber;
//	}
//	int GetSetNumber()
//	{
//		return setNumber;
//	}
//	void SetSetNumber(int _setNumber)
//	{
//		setNumber = _setNumber;
//	}
//	bool GetFull()
//	{
//		return full;
//	}
//	void SetFull()
//	{
//		full = true;
//	}
//	void UnSetFull()
//	{
//		full = false;
//	}
//protected:
//	bool full = false;
//	int setNumber = 0;
//	int slotnumber =0;
//	std::string type = "All";
//private:
//};
//
//class TextBoxUI : public InteractiveUI
//{
//public:
//	TextBoxUI(sf::Font& _font, int _fontSize, sf::Color  _fontColor, int _letterLimit, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer)
//		:InteractiveUI(_texture, _textureStart, _position, _objSize, _layer)
//	{
//		m_text = sf::Text("", _font, _fontSize);
//		m_text.setFillColor(_fontColor);
//		m_letterLimit = _letterLimit;
//	}
//	void WriteChar(char _letter)
//	{
//		if (m_str.size() < m_letterLimit)
//		{
//			m_str += _letter;
//			if (writeHidden)m_text.setString(m_text.getString() + '*');
//			else m_text.setString(m_str);
//			
//		}
//		
//		
//	}
//	void RemoveLetter()
//	{
//		if (m_str.size() != 0)
//		{
//			m_str.pop_back();
//			if (writeHidden)
//			{
//				std::string tmp = m_text.getString();
//				tmp.pop_back();
//				m_text.setString(tmp);
//			}
//			else m_text.setString(m_str);
//		}
//	}
//	void ResetText()
//	{
//		m_str = "";
//		m_text.setString(m_str);
//	};
//	void setHidden(bool _hidden)
//	{
//		writeHidden = _hidden;
//	}
//	virtual std::string GetType()
//	{
//		return "TextBoxUI";
//	}
//	bool IsHidden()
//	{
//		return writeHidden;
//	}
//	std::string GetString()
//	{
//		return m_str;
//	}
//protected:
//	sf::Text m_text;
//	std::string m_str;
//	int m_letterLimit;
//	bool writeHidden = false;
//private:
//	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
//	{
//		states.transform *= getTransform();
//		states.texture = &m_texture;
//		target.draw(m_vertices, states);
//		states.texture = NULL;
//		target.draw(m_text, states);
//	}
//};
//
//class TextFieldUI : public UI
//{
//public:
//	TextFieldUI(std::string _text, sf::Font& _font, int _fontSize, sf::Color  _fontColor, sf::Texture& _texture, sf::IntRect _textureStart, sf::Vector2f _position, sf::Vector2f _objSize, int _layer, bool _draw_BG = true)
//		:UI(_texture, _textureStart, _position, _objSize, _layer), draw_BG(_draw_BG)
//	{
//
//		m_text = sf::Text(_text, _font, _fontSize);
//		m_text.setFillColor(_fontColor);
//		//WŚRODKOWAĆ TEKST ROSKMIŃ
//		
//		m_text.setOrigin(m_text.getLocalBounds().width/2 , _objSize.y / 2 - (_objSize.y-m_text.getLocalBounds().height)/4);
//		m_text.setOrigin(this->getOrigin());
//		m_text.setPosition(_objSize.x/2, _objSize.y/2);
//		//m_text.setPosition(m_text.getLocalBounds().width / 2, _objSize.y/2);
//		/*statesText.transform = m_text.getTransform();*/
//		//TO DO
//		//ZAWIJANIE TEKSTU TO MATCH FIELD
//
//	}
//	virtual std::string GetType()
//	{
//		return "TextFieldUI";
//	}
//	void SetString(std::string _text)
//	{
//		_text = std::regex_replace(_text, std::regex("\\$n"), "\n");
//		m_text.setString(_text);
//	}
//protected:
//	sf::Text m_text;
//	bool draw_BG;
//private:
//	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
//	{
//		states.transform *= getTransform();
//		states.texture = &m_texture;
//		if(draw_BG)target.draw(m_vertices, states);
//		target.draw(m_text, states);
//	}
//};

//void clearQueue(std::queue<int>& q)
//{
//	std::queue<int> empty;
//	std::swap(q, empty);
//}
//
//


int main()
{
	int currentLayer = 0;
	//FILESYSTEM
	std::filesystem::path mainPath;


	mainPath = std::filesystem::current_path();
	Data_base DB((mainPath/"configfiles2.txt").generic_string());
	DB.Save((mainPath / "configfiles2.txt").generic_string());


	mainPath = std::filesystem::current_path();
	mainPath /="font";
	sf::Font font;
	if (!font.loadFromFile((mainPath/ "arial.ttf").generic_string()))
	{
	}
	sf::Font Fightfont;
	if (!Fightfont.loadFromFile((mainPath / "BossFight.otf").generic_string()))
	{
	}
		
	
	mainPath = std::filesystem::current_path();
	mainPath /= "textures";
	sf::Texture buttons;
	if (buttons.loadFromFile((mainPath / "UITEST.png").generic_string()))
	{

	}
	sf::Texture itemTex;
	if (itemTex.loadFromFile((mainPath / "itemss.png").generic_string()))
	{

	}
	sf::Texture nbuttons;
	if (nbuttons.loadFromFile((mainPath / "P1.png").generic_string()))
	{

	}
	sf::Texture heroTex;
	if (heroTex.loadFromFile((mainPath / "hero.png").generic_string()))
	{

	}
	sf::Texture classesTEX;
	if (classesTEX.loadFromFile((mainPath / "classes.png").generic_string()))
	{

	}
	sf::Texture logoTEX;
	if (logoTEX.loadFromFile((mainPath / "logo.png").generic_string()))
	{

	}
	sf::Texture bulTEX;
	if (bulTEX.loadFromFile((mainPath / "buildings.png").generic_string()))
	{

	}
	sf::Texture racesTEX;
	if (racesTEX.loadFromFile((mainPath / "races.png").generic_string()))
	{

	}
	sf::Texture BGTEX;
	if (BGTEX.loadFromFile((mainPath / "BG.jpg").generic_string()))
	{

	}

	mainPath = std::filesystem::current_path();


	//Regex filters
	auto viewsFuncChooseFromandIsPressed = [](std::unique_ptr<InteractiveUI >& x) {return (x->GetType() == "ChooseFromSetUI" && x->IsUIPressed()); };

	auto viewsFuncChooseFrom = [](std::unique_ptr<InteractiveUI >& x) {return (x->GetType() == "ChooseFromSetUI"); };

	auto viewsFuncMoveableUI = [](std::unique_ptr<InteractiveUI >& x) {return (x->GetType() == "MoveableUI"); };

	auto viewsFuncSlotForMUI = [](std::unique_ptr<InteractiveUI >& x) {return (x->GetType() == "SlotForMUI"); };

	auto viewsFuncTextBoxUI = [](std::unique_ptr<InteractiveUI >& x) { return x->GetType() == "TextBoxUI"; };

	auto viewsFuncUIandLayer = [&currentLayer](std::unique_ptr<UI >& x) { return x->whatLayer() == currentLayer && x->GetType() == "UI"; };

	auto viewsFuncTextFielUIandLayer = [&currentLayer](std::unique_ptr<UI >& x) { return x->whatLayer() == currentLayer && x->GetType() == "TextFieldUI"; };

	auto viewsFuncTextFielUIandErrorLayer = [&currentLayer](std::unique_ptr<UI >& x) { return x->whatLayer() == -currentLayer && x->GetType() == "TextFieldUI"; };



	std::shared_ptr<Account_Data> Current_Player;
	std::string t_l = "";
	std::string t_p = "";
	std::string t_race = "";
	std::string t_profesion = "";
	std::shared_ptr<Options> t_Settings = std::shared_ptr<Options>(new Options);

	
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game Window" , sf::Style::Close);

	bool goLogin;
	bool goNewAccount;
	bool goEnd;
	bool goGame1;
	bool goBack1;
	bool goBack2;
	bool goBack3;
	bool goRace2;
	bool goClass3;
	bool goBack4;
	bool goSettings4;
	bool goBack5;
	bool goGame5;
	bool goDungeon;
	bool goHouse;
	bool goInn;
	bool goMerchant;
	bool goQuitGame;
	bool goBack7;
	bool goStay7;
	bool goBack8;
	bool goFight;
	bool goBack9;
	bool goEQ9;
	bool goBack10;
	bool goBack11;
	bool goBack12;
	bool goBack13;

	bool errorLvLtoset;
	bool heroStarts;
	int errorLvL = 0;
	int chClass = 0;
	int chRace = 0;
	int heroHP = 0;
	int heroNowHP = 0;
	int enemyHP = 0;
	int enemyNowHP = 0;
	int layerBefor;
	std::queue<int> hits;
	sf::Clock hitTimer;



	std::vector<std::unique_ptr<UI>> interfaceUI;

	std::vector <std::vector<std::unique_ptr<InteractiveUI>>> interfaceInteractiveUI;
	
	sf::Sprite BG(BGTEX, sf::IntRect(0, 0, 1280, 720));
	
	interfaceInteractiveUI.resize(14);
	

	//Layer 0 AppStart
	UI title0(logoTEX, sf::IntRect(0, 0, 720, 720), sf::Vector2f(640, 160), sf::Vector2f(480, 320), 0);

	HoverAndPressedUI buttonNewGame(goNewAccount, nbuttons, sf::IntRect(0, 0, 70, 20), sf::Vector2f(640, 360), sf::Vector2f(320, 80), 0);
	HoverAndPressedUI buttonLogin(goLogin, nbuttons, sf::IntRect(0, 80, 42, 20), sf::Vector2f(640, 480), sf::Vector2f(320, 80), 0);
	HoverAndPressedUI buttonEnd(goEnd, nbuttons, sf::IntRect(0, 20, 38, 20), sf::Vector2f(640, 600), sf::Vector2f(180, 80), 0);

	//Layer 1 Login
	UI title1(logoTEX, sf::IntRect(0, 0, 720, 720), sf::Vector2f(640, 160), sf::Vector2f(480, 240), 1);
	UI titleLogin1(nbuttons, sf::IntRect(0, 80, 42, 20), sf::Vector2f(200, 320), sf::Vector2f(140, 60), 1);
	UI titlePassword1(nbuttons, sf::IntRect(42, 40, 42, 20), sf::Vector2f(200, 480), sf::Vector2f(140, 60), 1);

	HoverAndPressedUI buttonBack1(goBack1, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 1);
	HoverAndPressedUI buttonNext1(goGame1, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 1);
	TextBoxUI textboxLogin1(font, 42, sf::Color::White, 16, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(640, 320), sf::Vector2f(560, 60), 1);
	TextBoxUI textboxPassword1(font, 42, sf::Color::White, 16, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(640, 480), sf::Vector2f(560, 60), 1);
	textboxPassword1.setHidden(true);

	//Layer -1 komunikat o błędach w loginie/haśle
	TextFieldUI errorLogin1("Bledy Login", font, 42, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57),  sf::Vector2f(1100, 320), sf::Vector2f(250, 60), -1);
	TextFieldUI errorPassword1("Bledne Haslo", font, 42, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(1100, 480), sf::Vector2f(250, 60), -1);

	//Layer 2 NewAccount
	UI title2(logoTEX, sf::IntRect(0, 0, 720, 720), sf::Vector2f(640, 100), sf::Vector2f(480, 240), 2);
	UI titleLogin2(nbuttons, sf::IntRect(0, 80, 42, 20), sf::Vector2f(200, 240), sf::Vector2f(140, 60), 2);
	UI titlePassword21(nbuttons, sf::IntRect(42, 40, 42, 20), sf::Vector2f(200, 360), sf::Vector2f(140, 60), 2);
	UI titlePassword22(nbuttons, sf::IntRect(42, 40, 42, 20), sf::Vector2f(200, 480), sf::Vector2f(140, 60), 2);

	TextBoxUI textboxLogin2(font, 42, sf::Color::White, 16, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(640, 240), sf::Vector2f(560, 60), 2);
	TextBoxUI textboxPassword21(font, 42, sf::Color::White, 16, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(640, 360), sf::Vector2f(560, 60), 2);
	TextBoxUI textboxPassword22(font, 42, sf::Color::White, 16, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(640, 480), sf::Vector2f(560, 60), 2);
	HoverAndPressedUI buttonBack2(goBack2, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 2);
	HoverAndPressedUI buttonNext2(goRace2, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 2);
	textboxPassword21.setHidden(true);
	textboxPassword22.setHidden(true);

	//Layer -2 komunikat o błędach w danych do tworzenia konta
	TextFieldUI errorLogin2("Zajety Login", font, 42, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(1100, 240), sf::Vector2f(250, 60), -2);
	TextFieldUI errorPassword21("Zbyt Latwe", font, 42, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(1100, 360), sf::Vector2f(250, 60), -2);
	TextFieldUI errorPassword22("Haslo nie pasuje", font, 32, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(1100, 480), sf::Vector2f(250, 60), -2);


	//Layer 3 Race
	UI title3(logoTEX, sf::IntRect(0, 0, 720, 720), sf::Vector2f(640, 100), sf::Vector2f(480, 240), 3);	  

	ChooseFromSetUI buttonRace1(1,0, racesTEX, sf::IntRect(0, 0, 236, 355), sf::Vector2f(320, 290), sf::Vector2f(150, 180), 3);
	ChooseFromSetUI buttonRace2(2,0, racesTEX, sf::IntRect(236, 0, 236, 355), sf::Vector2f(320, 490), sf::Vector2f(150, 180), 3);
	ChooseFromSetUI buttonRace3(3,0, racesTEX, sf::IntRect(236 * 2, 0, 236, 355), sf::Vector2f(640, 290), sf::Vector2f(150, 180), 3);
	ChooseFromSetUI buttonRace4(4,0, racesTEX, sf::IntRect(236 * 3, 0, 236, 355), sf::Vector2f(640, 490), sf::Vector2f(150, 180), 3);
	ChooseFromSetUI buttonRace5(5,0, racesTEX, sf::IntRect(236 * 4, 0, 236, 355), sf::Vector2f(960, 290), sf::Vector2f(150, 180), 3);
	ChooseFromSetUI buttonRace6(6,0, racesTEX, sf::IntRect(236 * 5, 0, 236, 355), sf::Vector2f(960, 490), sf::Vector2f(150, 180), 3);
	HoverAndPressedUI buttonBack3(goBack3, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 3);
	HoverAndPressedUI buttonNext3(goClass3, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 3);
	buttonRace1.SetPressed();

	//Layer 4 Class
	UI title4(logoTEX, sf::IntRect(0, 0, 720, 720), sf::Vector2f(640, 100), sf::Vector2f(480, 240), 4);

	ChooseFromSetUI buttonClass1(1,0, classesTEX, sf::IntRect(0, 0, 220, 220), sf::Vector2f(300, 320), sf::Vector2f(240, 240), 4);
	ChooseFromSetUI buttonClass2(2,0, classesTEX, sf::IntRect(220, 0, 220, 220), sf::Vector2f(640, 320), sf::Vector2f(240, 240), 4);
	ChooseFromSetUI buttonClass3(3,0, classesTEX, sf::IntRect(440, 0, 220, 220), sf::Vector2f(980, 320), sf::Vector2f(240, 240), 4);
	HoverAndPressedUI buttonBack4(goBack4, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 4);
	HoverAndPressedUI buttonNext4(goSettings4, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 4);
	buttonClass1.SetPressed();

	//Layer 5 Settings
	UI title5(logoTEX, sf::IntRect(0, 0, 720, 720), sf::Vector2f(640, 100), sf::Vector2f(480, 240), 5);
	UI description51(nbuttons, sf::IntRect(72, 0, 72, 20), sf::Vector2f(420, 230), sf::Vector2f(200, 100), 5);
	UI description52(nbuttons, sf::IntRect(72, 20, 72, 20), sf::Vector2f(860, 230), sf::Vector2f(200, 100), 5);

	ChooseFromSetUI buttonSettings11(1,0, nbuttons, sf::IntRect(42, 80, 23, 20), sf::Vector2f(420, 370), sf::Vector2f(100, 100), 5);
	ChooseFromSetUI buttonSettings12(0,0, nbuttons, sf::IntRect(65, 80, 23, 20), sf::Vector2f(420, 480), sf::Vector2f(100, 100), 5);
	ChooseFromSetUI buttonSettings21(1,1, nbuttons, sf::IntRect(42, 80, 23, 20),  sf::Vector2f(860, 370), sf::Vector2f(100, 100), 5);
	ChooseFromSetUI buttonSettings22(0, 1, nbuttons, sf::IntRect(65, 80, 23, 20),  sf::Vector2f(860, 480), sf::Vector2f(100, 100), 5);
	HoverAndPressedUI buttonBack5(goBack5, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 5);
	HoverAndPressedUI buttonNext5(goGame5, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 5);
	buttonSettings12.SetPressed();
	buttonSettings22.SetPressed();

	//Layer 6 Wioska
	HoverAndPressedUI buttonDungeon(goDungeon,  bulTEX, sf::IntRect(0,0,720,800), sf::Vector2f(256, 480), sf::Vector2f(240, 400), 6);
	HoverAndPressedUI buttonHouse(goHouse,      bulTEX, sf::IntRect(720,0,720,800), sf::Vector2f(512, 480), sf::Vector2f(240, 400), 6);
	HoverAndPressedUI buttonInn(goInn,          bulTEX, sf::IntRect(1440,0,720,800), sf::Vector2f(768, 480), sf::Vector2f(240, 400), 6);
	HoverAndPressedUI buttonMerchant(goMerchant,bulTEX, sf::IntRect(2160,0,720,800), sf::Vector2f(1024, 480), sf::Vector2f(240, 400), 6);
	HoverAndPressedUI buttonQuitGame(goQuitGame, nbuttons, sf::IntRect(0, 20, 38, 20), sf::Vector2f(1200, 100), sf::Vector2f(60, 60), 6);


	//Layer 7 INFO CZY CHCĘ WYJŚĆ i SETTINGS
	UI title7(logoTEX, sf::IntRect(0, 0, 720, 720), sf::Vector2f(640, 100), sf::Vector2f(480, 240), 7);
	UI description7(nbuttons, sf::IntRect(72, 0, 72, 20), sf::Vector2f(640, 230), sf::Vector2f(200, 100), 7);

	ChooseFromSetUI buttonSettings71(1, 0, nbuttons, sf::IntRect(42, 80, 23, 20), sf::Vector2f(640, 370), sf::Vector2f(100, 100), 7);
	ChooseFromSetUI buttonSettings72(0, 0, nbuttons, sf::IntRect(65, 80, 23, 20), sf::Vector2f(640, 480), sf::Vector2f(100, 100), 7);
	HoverAndPressedUI buttonBack7(goBack7, nbuttons, sf::IntRect(0, 20, 38, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 7);
	HoverAndPressedUI buttonStay7(goStay7, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 7);
	buttonSettings71.SetPressed();


	//Layer 8 Loch
	TextFieldUI enemyText8("", font, 26, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(360, 240), sf::Vector2f(580, 360), 8);
	TextFieldUI levelText8("", font, 80, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(1000, 240), sf::Vector2f(500, 240), 8);

	HoverAndPressedUI buttonBack8(goBack8, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 8);
	HoverAndPressedUI buttonFight8(goFight, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 8);


	
	//Layer 9 Domek
	UI heroLook9(racesTEX, sf::IntRect(0, 0, 236, 355), sf::Vector2f(320, 240), sf::Vector2f(400, 360), 9);
	TextFieldUI heroText9("", font, 26, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(860, 240), sf::Vector2f(640, 360), 9);

	HoverAndPressedUI buttonBack9(goBack9, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 9);
	HoverAndPressedUI buttonEQ9(goEQ9, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 9);

	//Layer 10 Domek-Zmiana Eq

	SlotForMUI bagSlot0(0, 0, "All",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(180, 230), sf::Vector2f(100, 100), 10);
	SlotForMUI bagSlot1(1, 0, "All",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(180, 360), sf::Vector2f(100, 100), 10);
	SlotForMUI bagSlot2(2, 0, "All",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(180, 480), sf::Vector2f(100, 100), 10);
	SlotForMUI bagSlot3(3, 0, "All",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(400, 230), sf::Vector2f(100, 100), 10);
	SlotForMUI bagSlot4(4, 0, "All",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(400, 360), sf::Vector2f(100, 100), 10);
	SlotForMUI bagSlot5(5, 0, "All",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(400, 480), sf::Vector2f(100, 100), 10);
	SlotForMUI heroSlot0(0, 1,"Helm",  nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(860, 170), sf::Vector2f(100, 100), 10);
	SlotForMUI heroSlot1(1, 1,"Armor", nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(860, 280), sf::Vector2f(100, 100), 10);
	SlotForMUI heroSlot2(2, 1,"Weapon",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(740, 280), sf::Vector2f(100, 100), 10);
	SlotForMUI heroSlot3(3, 1,"Gloves",nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(980, 280), sf::Vector2f(100, 100), 10);
	MoveableUI bagItem0(0, itemTex, sf::IntRect( 0, 112, 16, 16), sf::Vector2f(180, 230), sf::Vector2f(90, 90), 10);
	MoveableUI bagItem1(1, itemTex, sf::IntRect(16, 112, 16, 16), sf::Vector2f(180, 360), sf::Vector2f(90, 90), 10);
	MoveableUI bagItem2(2, itemTex, sf::IntRect(32, 112, 16, 16), sf::Vector2f(180, 480), sf::Vector2f(90, 90), 10);
	MoveableUI bagItem3(3, itemTex, sf::IntRect(48, 112, 16, 16), sf::Vector2f(400, 230), sf::Vector2f(90, 90), 10);
	MoveableUI bagItem4(4, itemTex, sf::IntRect(64, 112, 16, 16), sf::Vector2f(400, 360), sf::Vector2f(90, 90), 10);
	MoveableUI bagItem5(5, itemTex, sf::IntRect(80, 112, 16, 16), sf::Vector2f(400, 480), sf::Vector2f(90, 90), 10);
	MoveableUI eQItem0(10, itemTex, sf::IntRect(112, 32, 16, 16), sf::Vector2f(860, 170), sf::Vector2f(90, 90), 10);
	MoveableUI eQItem1(11, itemTex, sf::IntRect(80, 32, 16, 16), sf::Vector2f(860, 280), sf::Vector2f(90, 90), 10);
	MoveableUI eQItem2(12, itemTex,  sf::IntRect(112, 48, 16, 16), sf::Vector2f(740, 280), sf::Vector2f(90, 90), 10);
	MoveableUI eQItem3(13, itemTex, sf::IntRect(112, 16, 16, 16),  sf::Vector2f(980, 280), sf::Vector2f(90, 90), 10);
	HoverAndPressedUI buttonBack10(goBack10, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 10);


	//Layer 11 Karczma
	TextFieldUI levelQuest1("", font, 40, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(380, 230), sf::Vector2f(400, 100), 11);
	TextFieldUI levelQuest2("", font, 40, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(380, 360), sf::Vector2f(400, 100), 11);
	TextFieldUI levelQuest3("", font, 40, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(380, 490), sf::Vector2f(400, 100), 11);
	TextFieldUI enemyText11("", font, 20, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(950, 360), sf::Vector2f(600, 360), 11);

	ChooseFromSetUI buttonQuest1(1, 0, nbuttons, sf::IntRect(84, 40, 23, 20), sf::Vector2f(120, 230), sf::Vector2f(100, 100), 11);
	ChooseFromSetUI buttonQuest2(2, 0, nbuttons, sf::IntRect(107, 40, 23, 20), sf::Vector2f(120, 360), sf::Vector2f(100, 100), 11);
	ChooseFromSetUI buttonQuest3(3, 0, nbuttons, sf::IntRect(84, 60, 23, 20), sf::Vector2f(120, 480), sf::Vector2f(100, 100), 11);
	HoverAndPressedUI buttonBack11(goBack11, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 11);
	HoverAndPressedUI buttonFight11(goFight, nbuttons, sf::IntRect(0, 60, 42, 20), sf::Vector2f(980, 620), sf::Vector2f(240, 60), 11);
	buttonQuest1.SetPressed();
	
	
	//Layer 12 Handlarz
	UI title12(buttons, sf::IntRect(128, 96, 32, 16), sf::Vector2f(640, 160), sf::Vector2f(480, 160), 12);
	TextFieldUI errorMoney12("!!! Nie masz juz kasy !!!", font, 50, sf::Color::Red, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(860, 560), sf::Vector2f(510, 80), -12);
	TextFieldUI money12("", font, 40, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(860, 400), sf::Vector2f(300, 50), 12);

	SlotForMUI bagSlot02(0, 0, "All",  nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(180, 230), sf::Vector2f(100, 100), 12);
	SlotForMUI bagSlot12(1, 0, "All",  nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(180, 360), sf::Vector2f(100, 100), 12);
	SlotForMUI bagSlot22(2, 0, "All",  nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(180, 480), sf::Vector2f(100, 100), 12);
	SlotForMUI bagSlot32(3, 0, "All",  nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(400, 230), sf::Vector2f(100, 100), 12);
	SlotForMUI bagSlot42(4, 0, "All",  nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(400, 360), sf::Vector2f(100, 100), 12);
	SlotForMUI bagSlot52(5, 0, "All",  nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(400, 480), sf::Vector2f(100, 100), 12);
	SlotForMUI tradeSlot0(0, 1, "All", nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(740, 170), sf::Vector2f(100, 100), 12);
	SlotForMUI tradeSlot1(1, 1, "All", nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(860, 170), sf::Vector2f(100, 100), 12);
	SlotForMUI tradeSlot2(2, 1, "All", nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(980, 170), sf::Vector2f(100, 100), 12);
	SlotForMUI sellSlot(0, 2, "All",   nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(860, 280), sf::Vector2f(460, 100), 12);
	MoveableUI bagItem02(0, itemTex, sf::IntRect(0, 112, 16, 16), sf::Vector2f(180, 230), sf::Vector2f(90, 90), 12);
	MoveableUI bagItem12(1, itemTex, sf::IntRect(16, 112, 16, 16), sf::Vector2f(180, 360), sf::Vector2f(90, 90), 12);
	MoveableUI bagItem22(2, itemTex, sf::IntRect(32, 112, 16, 16), sf::Vector2f(180, 480), sf::Vector2f(90, 90), 12);
	MoveableUI bagItem32(3, itemTex, sf::IntRect(48, 112, 16, 16), sf::Vector2f(400, 230), sf::Vector2f(90, 90), 12);
	MoveableUI bagItem42(4, itemTex, sf::IntRect(64, 112, 16, 16), sf::Vector2f(400, 360), sf::Vector2f(90, 90), 12);
	MoveableUI bagItem52(5, itemTex, sf::IntRect(80, 112, 16, 16), sf::Vector2f(400, 480), sf::Vector2f(90, 90), 12);
	MoveableUI tradeItem0(10, itemTex, sf::IntRect(112, 32, 16, 16), sf::Vector2f(740, 170), sf::Vector2f(90, 90), 12);
	MoveableUI tradeItem1(11, itemTex, sf::IntRect(80, 32, 16, 16), sf::Vector2f(860, 170), sf::Vector2f(90, 90), 12);
	MoveableUI tradeItem2(12, itemTex, sf::IntRect(112, 48, 16, 16), sf::Vector2f(980, 170), sf::Vector2f(90, 90), 12);
	HoverAndPressedUI buttonBack12(goBack12, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(300, 620), sf::Vector2f(240, 60), 12);


	//Layer 13 walka
	UI heroLook13(racesTEX, sf::IntRect(0, 0, 236, 255), sf::Vector2f(320, 240), sf::Vector2f(400, 360), 13);
	UI enemyLook13(heroTex, sf::IntRect(128, 112, 32, 16), sf::Vector2f(960, 240), sf::Vector2f(400, 360), 13);
	UI heroHP13( nbuttons, sf::IntRect(0, 157, 199, 59), sf::Vector2f(120, 450), sf::Vector2f(400, 60), 13,true);
	UI enemyHP13( nbuttons, sf::IntRect(0, 157, 199, 59), sf::Vector2f(760, 450), sf::Vector2f(400, 60), 13,true);
	TextFieldUI heroHPloss13("", Fightfont, 80, sf::Color::Red,             nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(240, 240), sf::Vector2f(100, 100), 13, false);
	TextFieldUI enemyHPloss13("", Fightfont, 80, sf::Color::Red,            nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(880, 240), sf::Vector2f(100, 100), 13, false);
	TextFieldUI enemyHPtext13("HP: 500/560", font, 38, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(960, 440), sf::Vector2f(240, 40), 13,false);
	TextFieldUI heroHPtext13("HP: 200/1000", font, 38, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(320, 440), sf::Vector2f(240, 40), 13,false);
	TextFieldUI summary13("Przegrales", font, 26, sf::Color::White,      nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(640, 420), sf::Vector2f(200, 300), -13);

	HoverAndPressedUI buttonBack13(goBack13, nbuttons, sf::IntRect(0, 40, 42, 20), sf::Vector2f(640, 620), sf::Vector2f(240, 60), -13);

	TextFieldUI itemDescription("", font, 24, sf::Color::White, nbuttons, sf::IntRect(0, 100, 57, 57), sf::Vector2f(0, 0), sf::Vector2f(360, 60), -10);




	//Dodawanie referencji do wskaźników w wektorach UI/InteractiveUI

	interfaceUI.push_back(std::unique_ptr<UI>(&title0));

	interfaceInteractiveUI[0].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonNewGame));
	interfaceInteractiveUI[0].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonLogin));
	interfaceInteractiveUI[0].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonEnd));

	interfaceUI.push_back(std::unique_ptr<UI>(&title1));
	interfaceUI.push_back(std::unique_ptr<UI>(&titleLogin1));
	interfaceUI.push_back(std::unique_ptr<UI>(&titlePassword1));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&errorLogin1));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&errorPassword1));

	interfaceInteractiveUI[1].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack1));
	interfaceInteractiveUI[1].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonNext1));
	interfaceInteractiveUI[1].push_back(std::unique_ptr<TextBoxUI>(&textboxLogin1));
	interfaceInteractiveUI[1].push_back(std::unique_ptr<TextBoxUI>(&textboxPassword1));

	interfaceUI.push_back(std::unique_ptr<UI>(&title2));
	interfaceUI.push_back(std::unique_ptr<UI>(&titleLogin2));
	interfaceUI.push_back(std::unique_ptr<UI>(&titlePassword21));
	interfaceUI.push_back(std::unique_ptr<UI>(&titlePassword22));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&errorLogin2));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&errorPassword21));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&errorPassword22));

	interfaceInteractiveUI[2].push_back(std::unique_ptr<TextBoxUI>(&textboxLogin2));
	interfaceInteractiveUI[2].push_back(std::unique_ptr<TextBoxUI>(&textboxPassword21));
	interfaceInteractiveUI[2].push_back(std::unique_ptr<TextBoxUI>(&textboxPassword22));
	interfaceInteractiveUI[2].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack2));
	interfaceInteractiveUI[2].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonNext2));

	interfaceUI.push_back(std::unique_ptr<UI>(&title3));

	interfaceInteractiveUI[3].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonRace1));
	interfaceInteractiveUI[3].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonRace2));
	interfaceInteractiveUI[3].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonRace3));
	interfaceInteractiveUI[3].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonRace4));
	interfaceInteractiveUI[3].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonRace5));
	interfaceInteractiveUI[3].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonRace6));
	interfaceInteractiveUI[3].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack3));
	interfaceInteractiveUI[3].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonNext3));

	interfaceUI.push_back(std::unique_ptr<UI>(&title4));

	interfaceInteractiveUI[4].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonClass1));
	interfaceInteractiveUI[4].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonClass2));
	interfaceInteractiveUI[4].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonClass3));
	interfaceInteractiveUI[4].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack4));
	interfaceInteractiveUI[4].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonNext4));

	interfaceUI.push_back(std::unique_ptr<UI>(&title5));
	interfaceUI.push_back(std::unique_ptr<UI>(&description51));
	interfaceUI.push_back(std::unique_ptr<UI>(&description52));

	interfaceInteractiveUI[5].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonSettings11));
	interfaceInteractiveUI[5].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonSettings12));
	interfaceInteractiveUI[5].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonSettings21));
	interfaceInteractiveUI[5].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonSettings22));
	interfaceInteractiveUI[5].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack5));
	interfaceInteractiveUI[5].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonNext5));

	interfaceInteractiveUI[6].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonDungeon));
	interfaceInteractiveUI[6].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonHouse));
	interfaceInteractiveUI[6].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonInn));
	interfaceInteractiveUI[6].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonMerchant));
	interfaceInteractiveUI[6].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonQuitGame));

	interfaceUI.push_back(std::unique_ptr<UI>(&title7));
	interfaceUI.push_back(std::unique_ptr<UI>(&description7));
	interfaceInteractiveUI[7].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonSettings71));
	interfaceInteractiveUI[7].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonSettings72));
	interfaceInteractiveUI[7].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack7));
	interfaceInteractiveUI[7].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonStay7));

	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&enemyText8));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&levelText8));

	interfaceInteractiveUI[8].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack8));
	interfaceInteractiveUI[8].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonFight8));

	interfaceUI.push_back(std::unique_ptr<UI>(&heroLook9));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&heroText9));

	interfaceInteractiveUI[9].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack9));
	interfaceInteractiveUI[9].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonEQ9));

																		 
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&bagSlot0));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&bagSlot1));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&bagSlot2));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&bagSlot3));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&bagSlot4));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&bagSlot5));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&heroSlot0));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&heroSlot1));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&heroSlot2));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<SlotForMUI>(&heroSlot3));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&bagItem0));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&bagItem1));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&bagItem2));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&bagItem3));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&bagItem4));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&bagItem5));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&eQItem0));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&eQItem1));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&eQItem2));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<MoveableUI>(&eQItem3));
	interfaceInteractiveUI[10].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack10));


	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&levelQuest1));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&levelQuest2));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&levelQuest3));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&enemyText11));

	interfaceInteractiveUI[11].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonQuest1));
	interfaceInteractiveUI[11].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonQuest2));
	interfaceInteractiveUI[11].push_back(std::unique_ptr<ChooseFromSetUI>(&buttonQuest3));
	interfaceInteractiveUI[11].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack11));
	interfaceInteractiveUI[11].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonFight11));


	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&money12));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&errorMoney12));

	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&bagSlot02));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&bagSlot12));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&bagSlot22));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&bagSlot32));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&bagSlot42));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&bagSlot52));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&tradeSlot0));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&tradeSlot1));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&tradeSlot2));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<SlotForMUI>(&sellSlot));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&bagItem02));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&bagItem12));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&bagItem22));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&bagItem32));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&bagItem42));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&bagItem52));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&tradeItem0));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&tradeItem1));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<MoveableUI>(&tradeItem2));
	interfaceInteractiveUI[12].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack12));

	
	interfaceUI.push_back(std::unique_ptr<UI>(&heroLook13));
	interfaceUI.push_back(std::unique_ptr<UI>(&enemyLook13));
	interfaceUI.push_back(std::unique_ptr<UI>(&heroHP13));
	interfaceUI.push_back(std::unique_ptr<UI>(&enemyHP13));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&heroHPloss13));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&enemyHPloss13));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&heroHPtext13));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&enemyHPtext13));
	interfaceUI.push_back(std::unique_ptr<TextFieldUI>(&summary13));

	interfaceInteractiveUI[13].push_back(std::unique_ptr<HoverAndPressedUI>(&buttonBack13));




    while (window.isOpen())
    {
		//Sprawdzenie i akcje związane z aktywacja konkretnego przycisku
		if (goBack1 || goBack2 || goBack3 || goBack4 || goBack5 || goBack7 || goStay7 || goBack8 || goBack9 || goBack10 || goBack11 || goBack12 || goBack13)
		{
			layerBefor = currentLayer;

			if (layerBefor <= 2)
			{
				for (auto& x : interfaceInteractiveUI[layerBefor] | std::views::filter(viewsFuncTextBoxUI))
				{		
					dynamic_cast<TextBoxUI&>(*x).ResetText();
				}
				errorLvL = 0;
				currentLayer = 0;
				goBack1 = goBack2 = false;
			}
			else if (layerBefor <= 5)
			{
				currentLayer--;
				goBack3 = goBack4 = goBack5 = false;
			}
			else if (layerBefor == 7)
			{
				bool tmp;
				for (auto& x : interfaceInteractiveUI[7] | std::views::filter(viewsFuncChooseFromandIsPressed))
				{
					tmp = dynamic_cast<ChooseFromSetUI&>(*x).GetValue();
				}
				Options t;
				t.FastGame = tmp;
				t.Hardcore = Current_Player->Get_Settings()->Get().Hardcore;
				Current_Player->Set_Settings(t);
				if (goStay7)
				{
					currentLayer = 6;
					goStay7 = false;
				}
				if (goBack7)
				{
					currentLayer = 0;
					goBack7 = false;
				}
			}
			else if (layerBefor == 10)
			{
				currentLayer = 9;
				std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
				std::string tmp_heroall = t_Hero->Get_Show_All();
				for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
				{
					dynamic_cast<TextFieldUI&>(*x).SetString(tmp_heroall);
				}
				goBack10 = false;
			}
			else if (layerBefor <= 13)
			{
				currentLayer = 6;
				errorLvL = 0;
				goBack8 = goBack9 = goBack11 = goBack12 = goBack13 = false;
			}
		}

		if (goEnd)window.close();
		if (goNewAccount)
		{
			currentLayer = 2;
			for (auto& x : interfaceInteractiveUI[2] | std::views::filter(viewsFuncTextBoxUI))
			{			
					dynamic_cast<TextBoxUI&>(*x).ResetText();
			}
			goNewAccount = false;
		}
		if (goLogin)
		{
			currentLayer = 1;
			goLogin = false;
		}
		if (goGame1)
		{
			bool pass = false;
			for (auto& x : interfaceInteractiveUI[1] | std::views::filter(viewsFuncTextBoxUI))
			{
					if (!dynamic_cast<TextBoxUI&>(*x).IsHidden())
					{
						std::string tmp = dynamic_cast<TextBoxUI&>(*x).GetString();
						if (DB.Check(tmp))
						{
							//DOBRY LOGIN
							t_l = tmp;
							t_p = DB.Get_Pass(tmp);
						}
						else
						{
							//BŁĘDNY LOGIN
							errorLvL = 1;
							break;
						}
					}
					if (dynamic_cast<TextBoxUI&>(*x).IsHidden())
					{
						std::string tmp = dynamic_cast<TextBoxUI&>(*x).GetString();
						if (t_p == tmp)
						{
							//OK Hasło
							pass = true;
						}
						else
						{
							//ZŁY Hasło
							errorLvL = 2;
						}
					}
			}

			if (pass)
			{
				
				errorLvL = 0;
				for (auto& x : interfaceInteractiveUI[1] | std::views::filter(viewsFuncTextBoxUI))
				{
						dynamic_cast<TextBoxUI&>(*x).ResetText();

				}
				currentLayer = 6;
				Current_Player = DB.Get_AD(t_l, t_p);
				t_race = Current_Player->Get_Hero_status()->Get_Race();

				sf::IntRect tmpRect;
				if (t_race == "Human")
				{
					tmpRect = sf::IntRect(0, 0, 236, 355);
				}
				else if (t_race == "Dwarf")
				{
					tmpRect = sf::IntRect(236, 0, 236, 355);
				}
				else if (t_race == "Elf")
				{
					tmpRect = sf::IntRect(236 * 2, 0, 236, 355);
				}
				else if (t_race == "Ork")
				{
					tmpRect = sf::IntRect(236 * 3, 0, 236, 355);
				}
				else if (t_race == "Goblin")
				{
					tmpRect = sf::IntRect(236 * 4, 0, 236, 355);
				}
				else if (t_race == "Undead")
				{
					tmpRect = sf::IntRect(236 * 5, 0, 236, 355);
				}

				heroLook9.ChangeTextuerCords(tmpRect);
				heroLook13.ChangeTextuerCords(tmpRect);
				
			}
			goGame1 = false;			
		}
		if (goRace2)
		{
			bool pass = false;
			t_l ="";
			t_p ="";
			for (auto& x : interfaceInteractiveUI[2] | std::views::filter(viewsFuncTextBoxUI))
			{
					if (!dynamic_cast<TextBoxUI&>(*x).IsHidden())
					{
						std::string tmp = dynamic_cast<TextBoxUI&>(*x).GetString();
						if (DB.Check(tmp))
						{
							//INFO O ZAJĘCIU
							errorLvL = 1;
							break;
						}
						else
						{
							t_l = tmp;
						}
					}
					if (dynamic_cast<TextBoxUI&>(*x).IsHidden())
					{
						std::string tmp = dynamic_cast<TextBoxUI&>(*x).GetString();
						if (t_p == "")t_p = tmp;
						else if (t_p != tmp)
						{
							//INNE HASŁO
							errorLvL = 3;
							break;
						}
						else
						{
							std::regex txt_regex("^(?=(.*[a-z]){1,})(?=(.*[A-Z]){1,})(?=(.*[0-9]){1,})(?=(.*[!@#$%^&*()\-__+.]){1,}).{4,}$");
							
							t_p = tmp;
							if (std::regex_match(tmp, txt_regex))
							{
						
								pass = true;
							}
							else
							{
								errorLvL = 2;
								break;
							}							
						}
					}

			}
			if (pass)
			{
				currentLayer = 3;	
				errorLvL = 0;
			}
			goRace2 = false;
		}
		if (goClass3)
		{
			for (auto& x : interfaceInteractiveUI[3] | std::views::filter(viewsFuncChooseFromandIsPressed))
			{
					chRace = dynamic_cast<ChooseFromSetUI&>(*x).GetValue();				
			}
			switch (chRace)
			{
				case 1:
				{
					t_race = "Human";
					break;
				}
				case 2:
				{
					t_race = "Dwarf";
					break;
				}
				case 3:
				{
					t_race = "Elf";
					break;
				}
				case 4:
				{
					t_race = "Ork";
					break;
				}
				case 5:
				{
					t_race = "Goblin";
					break;
				}
				case 6:
				{
					t_race = "Undead";
					break;
				}
			}
			currentLayer = 4;
			goClass3 = false;
		}
		if (goSettings4)
		{
			for (auto& x : interfaceInteractiveUI[4] | std::views::filter(viewsFuncChooseFromandIsPressed))
			{
					chClass = dynamic_cast<ChooseFromSetUI&>(*x).GetValue();
			}
			switch (chClass)
			{
				case 1:
				{
					t_profesion = "Warrior";
					break;
				}
				case 2:
				{
					t_profesion = "Mage";
					break;
				}
				case 3:
				{
					t_profesion = "Hunter";
					break;
				}
			}

			currentLayer = 5;
			goSettings4 = false;
		}
		if (goGame5)
		{
			for (auto& x : interfaceInteractiveUI[5] | std::views::filter(viewsFuncChooseFromandIsPressed))
			{
				if ( dynamic_cast<ChooseFromSetUI&>(*x).GetSetNumber() == 0)
					t_Settings->FastGame = dynamic_cast<ChooseFromSetUI&>(*x).GetValue();
				if ( dynamic_cast<ChooseFromSetUI&>(*x).GetSetNumber() == 1 )
					t_Settings->Hardcore = dynamic_cast<ChooseFromSetUI&>(*x).GetValue();
			}



			std::shared_ptr<Hero>t_H = std::shared_ptr<Hero>(new Hero(t_race, t_profesion));
			Current_Player = std::shared_ptr<Account_Data>(new Account_Data(t_l, t_p, t_H, t_Settings));
			int t_Level = Current_Player->Get_Hero_status()->Get_Level();
			for (int i = 0; i < 3; i++)
			{
				std::pair<std::string, std::string> t_pair = DB.Get_New_Quest();
				std::string t_Short_Description = t_pair.first;
				std::string t_Description = t_pair.second;
				std::string t_Proffesion = Random_Proffesion();
				std::string t_Monster_Name = DB.Get_New_Monster_Name(t_Proffesion);
				std::shared_ptr<Quest> t_Q = Current_Player->Get_Inn_status()->Get_Quest(i);
				std::string t_Type = "Weapon";
				std::string t_Weapon_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
				t_Q->Make_New_Quest(t_Short_Description, t_Description, t_Level, t_Proffesion, t_Monster_Name, t_Weapon_Name);
			}
			DB.Add_account(*Current_Player);
			sf::IntRect tmpRect;
			if (t_race == "Human")
			{
				tmpRect = sf::IntRect(0, 0, 236, 355);
			}
			else if (t_race == "Dwarf")
			{
				tmpRect = sf::IntRect(236, 0, 236, 355);
			}
			else if (t_race =="Elf")
			{
				tmpRect = sf::IntRect(236 * 2, 0, 236, 355);
			}
			else if (t_race == "Ork")
			{
				tmpRect = sf::IntRect(236 * 3, 0, 236, 355);
			}
			else if (t_race == "Goblin")
			{
				tmpRect = sf::IntRect(236 * 4, 0, 236, 355);
			}
			else if (t_race == "Undead")
			{
				tmpRect = sf::IntRect(236 * 5, 0, 236, 355);
			}

			heroLook9.ChangeTextuerCords(tmpRect);
			heroLook13.ChangeTextuerCords(tmpRect);

			currentLayer = 6;
			goGame5 = false;

		}
		if (goDungeon)
		{
			currentLayer = 8;
			std::shared_ptr<Dungeon> t_Dungeon = Current_Player->Get_Dungeon_status();
			std::string dungeon_lvl = "\tPietro: "; 
			dungeon_lvl += std::to_string(t_Dungeon->Get_Floor());
			dungeon_lvl += ",\n Przeciwnik: ";
			dungeon_lvl += std::to_string(t_Dungeon->Get_Progress());
			dungeon_lvl += "\n";
			if (t_Dungeon->Get_Opponent() == nullptr)t_Dungeon->Reset_Oponent(DB.Get_Dungeon_Monster(t_Dungeon->Get_Floor(), t_Dungeon->Get_Progress()));
			std::string dungeon_all = t_Dungeon->Get_Opponent()->Get_Show_All();
			bool tlt = true;
			for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
			{
					if (tlt)
					{
						dynamic_cast<TextFieldUI&>(*x).SetString(dungeon_all);
						tlt = false;
					}
					else
					{
						dynamic_cast<TextFieldUI&>(*x).SetString(dungeon_lvl);
						break;
					}
			}
			goDungeon = false;
		}
		if (goFight)
		{
			layerBefor = currentLayer;
			currentLayer = 13;
			std::string summarySTR = "";
			heroStarts = false;
			clearQueue(hits);
			heroHP = Current_Player->Get_Hero_status()->Get_HP();
			heroNowHP = heroHP;

			std::shared_ptr<Dungeon> t_Dungeon = Current_Player->Get_Dungeon_status();
			std::shared_ptr<Inn> t_Inn = Current_Player->Get_Inn_status();
			std::shared_ptr<Quest> t_Q;
			std::shared_ptr<Monster> t_Monster;

			if (layerBefor == 8)
			{
				enemyHP = t_Dungeon->Get_Opponent()->Get_HP();
				t_Monster = t_Dungeon->Get_Opponent();
				enemyNowHP = enemyHP;
			}
			else if (layerBefor == 11)
			{

				int tmpQuestNR = 1;
				for (auto& x : interfaceInteractiveUI[11] | std::views::filter(viewsFuncChooseFromandIsPressed))
				{
						tmpQuestNR = dynamic_cast<ChooseFromSetUI&>(*x).GetValue();
				}
				t_Q = Current_Player->Get_Inn_status()->Get_Quest(tmpQuestNR - 1);
				t_Monster = t_Q->Get_Opponent();
				enemyHP = t_Q->Get_Opponent()->Get_HP();
				enemyNowHP = enemyHP;
			}
			int tmpMP = 0;
			std::string t_MonstProff = t_Monster->Get_Profesion();
			if (t_MonstProff == "Warrior")
			{
				tmpMP = 0;
			}
			else if (t_MonstProff == "Mage")
			{
				tmpMP = 1;

			}
			else if (t_MonstProff == "Hunter")
			{
				tmpMP = 2;
			}
			


		
			int tmp2 = 0;
			for (auto& x : interfaceUI | std::views::filter(viewsFuncUIandLayer))
			{
					if (tmp2 == 1)
					{
						x->ChangeTextuerCords(sf::IntRect(300 * tmpMP, 0, 300, 300));
					}
					if (tmp2 == 2 || tmp2 == 3)
					{
						x->ChangeRightSize(400.f);

					}
					tmp2++;
			}

			int tmp = 0;

			for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
			{
					if (tmp == 0 || tmp == 1)
					{
						std::string stmp = "";
						dynamic_cast<TextFieldUI&>(*x).SetString(stmp);

					}
					else if (tmp==2)
					{
						std::string stmp = "HP: "+std::to_string(heroHP)+"/"+std::to_string(heroHP);
						dynamic_cast<TextFieldUI&>(*x).SetString(stmp);
					
					}
					else if(tmp==3)
					{
						std::string stmp = "HP: " + std::to_string(enemyHP) + "/" + std::to_string(enemyHP);
						dynamic_cast<TextFieldUI&>(*x).SetString(stmp);
						break;
					}
					tmp++;
			}




			if (layerBefor == 8)
			{

				if (Fight(Current_Player->Get_Hero_status(), t_Dungeon->Get_Opponent(), Current_Player->Get_Settings()->Get(), hits, heroStarts))
				{

					int t_Level = Current_Player->Get_Hero_status()->Get_Level();
					int t_expirience = 2 * (t_Level * (200 + rand() % 200));
					int t_gold = (rand() % (t_Level)+t_Level + 2) * 2;

					summarySTR += "Zwyciestwo\n";
					summarySTR += "Zdobyto:  \nGolda: " + std::to_string(t_gold) + "\nDoswiadczenia:\n " + std::to_string(t_expirience) ;
					Current_Player->Get_Hero_status()->Increse_Gold(t_gold);
					Current_Player->Get_Hero_status()->Increase_Expirience(t_expirience);
					bool b_suprice = rand() % 2;
					if (b_suprice)
					{
						if (!(Current_Player->Get_Hero_status()->Get_Equipment()->Bag_full()))
						{
							std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
							std::string t_Type = Random_Type();
							std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
							std::shared_ptr<Item> t_ptr;
							if (t_Type == "Weapon")
							{
								t_ptr = std::shared_ptr<Weapon>(new Weapon(t_Proffesion, t_Level, t_Name, 2));
							}
							else
							{
								t_ptr = std::shared_ptr<Armor>(new Armor(t_Proffesion, t_Level, t_Type, t_Name, 3));
							}
							Current_Player->Get_Hero_status()->Get_Equipment()->Add_Item(t_ptr);
							summarySTR += "\nUdalo sie\n zdobyc nowy\n przedmiot!\n ";
						}
						else
						{
							summarySTR += "TY IDIOTO NIE\n MASZ MIEJSCA\n W PLECAKU HEHE,\n PRZEPAŁ CI\n SUPER PRZEDMIOT";
						}
					}

					if (t_Dungeon->Get_Floor() == 2 && t_Dungeon->Get_Progress() == 10)
					{

					}


					t_Dungeon->Go_Next();
					t_Dungeon->Reset_Oponent(DB.Get_Dungeon_Monster(t_Dungeon->Get_Floor(), t_Dungeon->Get_Progress()));

					std::shared_ptr<Merchant> t_Merchant = Current_Player->Get_Merchant_status();
					std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
					t_Level = Current_Player->Get_Hero_status()->Get_Level();

					for (int i = 1; i < 4; i++)
					{
						std::string t_Type = Random_Type();
						std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
						t_Merchant->Add_New_Item(i, t_Level, t_Proffesion, t_Name, t_Type);
					}
				}
				else
				{
					summarySTR += "Porazka\n";
					if (Current_Player->Get_Settings()->Hardcore)
					{
						summarySTR += "Twoja przygoda\n sie zakonczyla !";
						Current_Player->Lost();
					}
				}


			}
			else if (layerBefor == 11)
			{

				if (Fight(Current_Player->Get_Hero_status(), t_Q->Get_Opponent(), Current_Player->Get_Settings()->Get(), hits, heroStarts))
				{
					summarySTR += "Zwyciestwo\n";
					summarySTR += "Zdobyto:  \nGolda: "  + std::to_string(t_Q->Get_Gold()) + "\nDoswiadczenia:\n " + std::to_string(t_Q->Get_Expirience()) ;
					Current_Player->Get_Hero_status()->Increse_Gold(t_Q->Get_Gold());
					Current_Player->Get_Hero_status()->Increase_Expirience(t_Q->Get_Expirience());
				}
				else
				{

					summarySTR += "Porazka\n";
					if (Current_Player->Get_Settings()->Hardcore)
					{
						summarySTR += "Twoja przygoda\n sie zakonczyla !\n";
						Current_Player->Lost();
					}
					DB.Save((mainPath / "configfiles2.txt").generic_string());
				}

				std::shared_ptr<Merchant> t_Merchant = Current_Player->Get_Merchant_status();
				std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
				int t_Level = Current_Player->Get_Hero_status()->Get_Level();

				for (int i = 1; i < 4; i++)
				{
					std::string t_Type = Random_Type();
					std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
					t_Merchant->Add_New_Item(i, t_Level, t_Proffesion, t_Name, t_Type);
				}

				for (int i = 0; i < 3; i++)
				{
					std::pair<std::string, std::string> t_pair = DB.Get_New_Quest();
					std::string t_Short_Description = t_pair.first;
					std::string t_Description = t_pair.second;
					t_Proffesion = Random_Proffesion();
					std::string t_Monster_Name = DB.Get_New_Monster_Name(t_Proffesion);
					std::shared_ptr<Quest> t_Q = Current_Player->Get_Inn_status()->Get_Quest(i);
					std::string t_Type = "Weapon";
					std::string t_Weapon_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
					t_Q->Make_New_Quest(t_Short_Description, t_Description, t_Level, t_Proffesion, t_Monster_Name, t_Weapon_Name);
				}
			}





			tmp = 0;
			for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandErrorLayer))
			{
						dynamic_cast<TextFieldUI&>(*x).SetString(summarySTR);
			}



			hitTimer.restart();

			if (Current_Player->Get_Settings()->FastGame)
			{
				int thit = hits.back();
				int hitsSize = hits.size();
				bool btmp = heroStarts;
				for (int i = 0; i < hitsSize-1 ; i++)
				{
					if (btmp)
					{
						int tthit = hits.front();
						
						enemyNowHP -= tthit;
					}
					else
					{
						int tthit = hits.front();
						heroNowHP -= tthit;
					}
					hits.pop();
					btmp = !btmp;
				}



				if (hitsSize % 2 == 0)
				{
					heroStarts = !heroStarts;
				}
			}
			DB.Save((mainPath / "configfiles2.txt").generic_string());
			goFight = false;
		}
		if (goHouse)
		{
			currentLayer = 9;
			std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
			std::string tmp_heroall = t_Hero->Get_Show_All();
			for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
			{
					dynamic_cast<TextFieldUI&>(*x).SetString(tmp_heroall);
			}
			goHouse = false;
		}
		if (goEQ9)
		{
			currentLayer = 10;
			goEQ9 = false;
			std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
			std::shared_ptr<Equipment> t_Equipment = t_Hero->Get_Equipment();
			int bagSize =t_Equipment->Get_Bag_Size();
			int bagSizeSlot =t_Equipment->Get_Bag_Size();
			bagSize = 6;

		
			for (auto& x : interfaceInteractiveUI[10] | std::views::filter(viewsFuncMoveableUI))
			{
					//wypełnianie baga
					if (bagSize > 0)
					{
						std::shared_ptr<Item> t_item = t_Equipment->Get_Item(6 - bagSize);
						sf::IntRect t_Rect(0, 112, 16, 16);
						if (t_item != nullptr)
						{
							//Ustawienie odpowiedniej tekstury
							if (t_item->Get_Type() == "Weapon")		t_Rect = sf::IntRect(112, 48, 16, 16);
							else if (t_item->Get_Type() == "Helm")	t_Rect = sf::IntRect(112, 32, 16, 16);
							else if (t_item->Get_Type() == "Armor")	t_Rect = sf::IntRect(80, 32, 16, 16);
							else if (t_item->Get_Type() == "Gloves")t_Rect = sf::IntRect(112, 16, 16, 16);
							x->ChangeTextuerCords(t_Rect);
							dynamic_cast<MoveableUI&>(*x).SetActive();

						}
						else
						{
							dynamic_cast<MoveableUI&>(*x).SetUnActive();
						}
						bagSize--;
					}
					else if (bagSize == 0)
					{
						dynamic_cast<MoveableUI&>(*x).SetActive();
					}
			}
			for (auto& x : interfaceInteractiveUI[10] | std::views::filter(viewsFuncSlotForMUI))
			{
					//wypełnianie baga
					if (bagSizeSlot > 0)
					{
						std::shared_ptr<Item> t_item = t_Equipment->Get_Item(6 - bagSizeSlot);

						if (t_item != nullptr)
						{

							dynamic_cast<SlotForMUI&>(*x).SetFull();

						}
						else
						{
							dynamic_cast<SlotForMUI&>(*x).UnSetFull();
						}
						bagSizeSlot--;
					}
					else if (bagSizeSlot == 0)
					{
						//wypełnianie eq
						dynamic_cast<SlotForMUI&>(*x).SetFull();
					}
			}
		}
		if (goInn)
		{
			currentLayer = 11;
			goInn = false;

			std::shared_ptr<Inn> t_Inn = Current_Player->Get_Inn_status();
			std::shared_ptr<Quest> t_Q1 = t_Inn->Get_First_Quest();
			std::shared_ptr<Quest> t_Q2 = t_Inn->Get_Second_Quest();
			std::shared_ptr<Quest> t_Q3 = t_Inn->Get_Third_Quest();

			std::string q1_Descp = t_Q1->Get_Short_Description();
			std::string q2_Descp = t_Q2->Get_Short_Description();
			std::string q3_Descp = t_Q3->Get_Short_Description();
			std::string q1_LONGDescp = "Quest: "+t_Q1->Get_Description() + "\nExp: "
				+std::to_string(t_Q1->Get_Expirience())+"\nGold: "+ std::to_string(t_Q1->Get_Gold())
				+"\nEnemy: \n" + t_Q1->Get_Opponent()->Get_Show_All();

			int tlt = 0;
			for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
			{
					if (tlt==0)
					{
						dynamic_cast<TextFieldUI&>(*x).SetString(q1_Descp);
						tlt++;
					}
					else if(tlt ==1)
					{
						dynamic_cast<TextFieldUI&>(*x).SetString(q2_Descp);
						tlt++;
					}
					else if (tlt == 2)
					{
						dynamic_cast<TextFieldUI&>(*x).SetString(q3_Descp);
						tlt++;
						break;
					}
			}

		}
		if (goMerchant)
		{
			currentLayer = 12;
			goMerchant = false;
			std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
			std::shared_ptr<Equipment> t_Equipment = t_Hero->Get_Equipment();
			std::shared_ptr<Merchant> t_Merch = Current_Player->Get_Merchant_status();
			int bagSize = t_Equipment->Get_Bag_Size();
			int bagSizeSlot = t_Equipment->Get_Bag_Size();
			bagSize = 6;
			int poc = 0;
		

			for (auto& x : interfaceInteractiveUI[12] | std::views::filter(viewsFuncMoveableUI))
			{
					//wypełnianie baga
					if (bagSize > 0)
					{
						std::shared_ptr<Item> t_item = t_Equipment->Get_Item(6 - bagSize);
						sf::IntRect t_Rect(0, 112, 16, 16);
						if (t_item != nullptr)
						{
							//Ustawienie odpowiedniej tekstury
							if (t_item->Get_Type() == "Weapon")		t_Rect = sf::IntRect(112, 48, 16, 16);
							else if (t_item->Get_Type() == "Helm")	t_Rect = sf::IntRect(112, 32, 16, 16);
							else if (t_item->Get_Type() == "Armor")	t_Rect = sf::IntRect(80, 32, 16, 16);
							else if (t_item->Get_Type() == "Gloves")t_Rect = sf::IntRect(112, 16, 16, 16);
							//ustawienie odpoiedniej lokalizacji elementu
							x->ChangeTextuerCords(t_Rect);
							dynamic_cast<MoveableUI&>(*x).SetActive();

						}
						else
						{
							dynamic_cast<MoveableUI&>(*x).SetUnActive();
						}
						bagSize--;
					}
					else if (bagSize == 0)
					{	
						//wypełnianie eq
						std::shared_ptr<Item> t_item = t_Merch->Get_Item(poc);
						sf::IntRect t_Rect(0, 112, 16, 16);
						if (t_item->Get_Type() == "Weapon")		t_Rect = sf::IntRect(112, 48, 16, 16);
						else if (t_item->Get_Type() == "Helm")	t_Rect = sf::IntRect(112, 32, 16, 16);
						else if (t_item->Get_Type() == "Armor")	t_Rect = sf::IntRect(80, 32, 16, 16);
						else if (t_item->Get_Type() == "Gloves")t_Rect = sf::IntRect(112, 16, 16, 16);
						x->ChangeTextuerCords(t_Rect);
						dynamic_cast<MoveableUI&>(*x).SetActive();
						poc++;

					}
			}
			for (auto& x : interfaceInteractiveUI[12] | std::views::filter(viewsFuncSlotForMUI))
			{
					//wypełnianie baga
					if (bagSizeSlot > 0)
					{
						std::shared_ptr<Item> t_item = t_Equipment->Get_Item(6 - bagSizeSlot);

						if (t_item != nullptr)
						{

							dynamic_cast<SlotForMUI&>(*x).SetFull();

						}
						else
						{
							dynamic_cast<SlotForMUI&>(*x).UnSetFull();
						}
						bagSizeSlot--;
					}
					else if (bagSizeSlot == 0)
					{
						//wypełnianie eq
						//Mechanta
						dynamic_cast<SlotForMUI&>(*x).SetFull();
					}


			}
			for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
			{
					std::string goldText = "Ilosc zlota: " + std::to_string(t_Hero->Get_Gold());
					dynamic_cast<TextFieldUI&>(*x).SetString(goldText);
			}
		}
		if (goQuitGame)
		{
			currentLayer = 7;
			bool tmp = Current_Player->Get_Settings()->Get().FastGame;

	
			for (auto& x : interfaceInteractiveUI[7] | std::views::filter(viewsFuncChooseFrom))
			{
				if (dynamic_cast<ChooseFromSetUI&>(*x).GetValue() == tmp)
					x->SetPressed();
				if (x->IsUIPressed() && dynamic_cast<ChooseFromSetUI&>(*x).GetValue() != tmp )
					x->UnSetPressed();	
			}
			goQuitGame = false;
			errorLvL = 0;
		}

		//if (goBack1)
		//{
		//	for (auto& x : interfaceInteractiveUI[1] | std::views::filter(viewsFuncTextBoxUI))
		//	{
		//		//if ( x->GetType() == "TextBoxUI")				
		//			dynamic_cast<TextBoxUI&>(*x).ResetText();
		//	}
		//	errorLvL = 0;
		//	currentLayer = 0;
		//	goBack1 = false;
		//}
		//if (goBack2)
		//{
		//	for (auto& x : interfaceInteractiveUI[2] | std::views::filter(viewsFuncTextBoxUI))
		//	{
		//		//if ( x->GetType() == "TextBoxUI")
		//			dynamic_cast<TextBoxUI&>(*x).ResetText();
		//	}
		//	errorLvL = 0;
		//	currentLayer=0;
		//	goBack2 = false;
		//}
		//if (goBack3)
		//{
		//	currentLayer = 2;
	//		goBack3 = false;
	//	}
		//		if (goBack4)
		//{
		//	currentLayer = 3;
	//		goBack4 = false;
		//}
		//	if (goBack5)
		//{
		//	currentLayer = 4;
		//	goBack5 = false;
		//}
		//if (goBack8)
		//{
		//	currentLayer = 6;
		//	goBack8 = false;
		//}
		//if (goBack7 || goStay7)
		//{
		//	bool tmp;
		//	for (auto& x : interfaceInteractiveUI[7] | std::views::filter(viewsFuncChooseFromandIsPressed))
		//	{
		//		//if (x->GetType() == "ChooseFromSetUI" && x->IsUIPressed() )
		//			tmp= dynamic_cast<ChooseFromSetUI&>(*x).GetValue();
		//	}
		//	Options t;
		//	t.FastGame = tmp;
		//	t.Hardcore = Current_Player->Get_Settings()->Get().Hardcore;
		//	Current_Player->Set_Settings(t);
		//	if (goStay7)
		//	{
		//		currentLayer = 6;
		//		goStay7 = false;
		//	}
		//	if (goBack7)
		//	{
		//		currentLayer = 0;
		//		goBack7 = false;
		//	}
		//		
		//}
		//if (goBack13)
		//{
		//	errorLvL = 0;
		//	currentLayer = 6;
		//	goBack13 = false;
		//}
		//if (goBack9)
		//{
		//	currentLayer = 6;
		//	goBack9 = false;
		//}
		//if (goBack10)
		//{
		//	currentLayer = 9;
		//	std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
		//	std::string tmp_heroall = t_Hero->Get_Show_All();
		//	for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
		//	{
		//		//if (x->whatLayer() == currentLayer && x->GetType() == "TextFieldUI")
		//		//{
		//			dynamic_cast<TextFieldUI&>(*x).SetString(tmp_heroall);
		//			//break;
		//		//}
		//	}
		//	goBack10 = false;
		//}
		//if (goBack11)
		//{
		//	currentLayer = 6;
		//	goBack11 = false;
		//}
		//if (goBack12)
		//{
		//	currentLayer = 6;
		//	goBack12 = false;
		//	errorLvL = 0;
		//}



		//Pętla ewentów SFML'a
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (auto& x : interfaceInteractiveUI[currentLayer])
					{

							if (x->IsMouseOn(sf::Mouse::getPosition(window)))
							{
								x->SetPressed();
								if (x->GetType() == "ChooseFromSetUI") 
								{
									int tmp_sN = dynamic_cast<ChooseFromSetUI&>(*x).GetSetNumber();
									for (auto& z : interfaceInteractiveUI[currentLayer])
									{
										if (z->GetType() == "ChooseFromSetUI" && z != x && dynamic_cast<ChooseFromSetUI&>(*z).GetSetNumber() == tmp_sN)
										{
											z->UnSetPressed();
										}
									}
								}
								if (x->GetType() == "MoveableUI" && dynamic_cast<MoveableUI&>(*x).GetActive())
								{
									dynamic_cast<MoveableUI&>(*x).setAttached();
								}

							}
							else
							{
								if (x->GetType() != "ChooseFromSetUI")x->UnSetPressed();
							}

					}

				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				for (auto& x : interfaceInteractiveUI[currentLayer])
				{

						if (x->GetType() == "HoverAndPressedUI")
						{
							if (x->IsMouseOn(sf::Mouse::getPosition(window)) && x->IsUIPressed())
							{
								dynamic_cast<HoverAndPressedUI&>(*x).ActiveAction();
								x->UnSetPressed();
							}
							else
							{
								x->UnSetPressed();
							}
						}
						if (x->GetType() == "MoveableUI")
						{
							if (dynamic_cast<MoveableUI&>(*x).GetAttached())
							{
								for (auto& z : interfaceInteractiveUI[currentLayer])
								{
									if (z->GetType() == "SlotForMUI")
									{
										if (z->IsMouseOn(sf::Mouse::getPosition(window)))
										{
											int itemNumber = dynamic_cast<MoveableUI&>(*x).GetSlotNumber();
											int slotsetNumber = dynamic_cast<SlotForMUI&>(*z).GetSetNumber();
											int slotNumber = dynamic_cast<SlotForMUI&>(*z).GetSlotNumber();
											std::string slotType = dynamic_cast<SlotForMUI&>(*z).GetSlotType();
											std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
											std::shared_ptr<Equipment> t_Equipment = t_Hero->Get_Equipment();
											if (slotsetNumber == 0)
											{
												if (itemNumber < 10)
												{
													//Zmiana w samym bagu
													t_Equipment->Items_Order_Change(itemNumber, slotNumber);
													//Zamiana tekstur
													int i = 0;
													int y = 0;
													for (auto& x : interfaceInteractiveUI[currentLayer])
													{
														if (x->GetType() == "MoveableUI")
														{
															if (i < 6)
															{
																std::shared_ptr<Item> t_item = t_Equipment->Get_Item(i);
																if (t_item != nullptr)
																	dynamic_cast<MoveableUI&>(*x).SetActive();
																else
																	dynamic_cast<MoveableUI&>(*x).SetUnActive();
																i++;
															}
															

														}
														else if (x->GetType() == "SlotForMUI")
														{
															if (y < 6)
															{
																std::shared_ptr<Item> t_item = t_Equipment->Get_Item(y);

																if (t_item != nullptr)
																	dynamic_cast<SlotForMUI&>(*x).SetFull();
																else
																	dynamic_cast<SlotForMUI&>(*x).UnSetFull();
																y++;
															}
														}
														if (i >= 6 && y >= 6)break;
														
													}
												}
												else
												{
													//Zmiana z EQ->BAGA
													if (currentLayer == 10)
													{
														std::shared_ptr<Item> t_item = t_Equipment->Get_Item(slotNumber);
														if (t_item != nullptr)
														{
															std::string eQItemType;
															if (itemNumber == 10)eQItemType = "Helm";
															else if (itemNumber == 11)eQItemType = "Armor";
															else if (itemNumber == 12)eQItemType = "Weapon";
															else if (itemNumber == 13)eQItemType = "Gloves";

															if (t_item->Get_Type() == eQItemType)
															{
																t_Equipment->Equip(slotNumber);										
															}
														}
														else
														{
															//zdjęcie przedmiotu jest narazie nie możliwe
														}
													}
													else if (currentLayer == 12)
													{
														std::shared_ptr<Merchant> t_Merch = Current_Player->Get_Merchant_status();
														if (t_Merch->Buy_Item(itemNumber-9, Current_Player->Get_Hero_status()))
														{
															std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
															std::string t_Type = Random_Type();
															std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
															int t_Level = Current_Player->Get_Hero_status()->Get_Level();
															t_Merch->Add_New_Item(itemNumber - 9, t_Level, t_Proffesion, t_Name, t_Type);

															int i = 0;
															int y = 0;
															for (auto& x : interfaceInteractiveUI[12])
															{
																if (x->GetType() == "MoveableUI")
																{
																	if (i < 6)
																	{
																		std::shared_ptr<Item> t_item = t_Equipment->Get_Item(i);
																		if (t_item != nullptr)
																			dynamic_cast<MoveableUI&>(*x).SetActive();
																		else
																			dynamic_cast<MoveableUI&>(*x).SetUnActive();
																		i++;
																	}
																	//BLAD dodaj se kasy

																}
																else if (x->GetType() == "SlotForMUI")
																{
																	if (y < 6) {
																		std::shared_ptr<Item> t_item = t_Equipment->Get_Item(y);

																		if (t_item != nullptr)
																			dynamic_cast<SlotForMUI&>(*x).SetFull();
																		else
																			dynamic_cast<SlotForMUI&>(*x).UnSetFull();
																		y++;
																	}

																}
																if (i >= 6 && y >= 6)break;


															}


															for (auto& x : interfaceUI)
															{
																if (x->whatLayer() == currentLayer && x->GetType() == "TextFieldUI")
																{
																	std::string goldText = "Ilosc zlota: " + std::to_string(t_Hero->Get_Gold());
																	dynamic_cast<TextFieldUI&>(*x).SetString(goldText);
																}
															}
															errorLvL = 0;

														}
														else
														{
															errorLvL = 1;
														}
													}


												}
											}
											else if (slotsetNumber == 1)
											{
												if (itemNumber < 10)
												{
													//Zmiana z Bag->EQ
													if (currentLayer == 10)
													{
														
														std::shared_ptr<Item> t_item = t_Equipment->Get_Item(itemNumber);
														if (t_item->Get_Type() == slotType)
														{
															t_Equipment->Equip(itemNumber);
														}
													}

												}
												else
												{
													//Zmiana w samym EQ (JESTEŚ  GŁUPI)
												}
											}
											else if (slotsetNumber == 2)
											{
												if (currentLayer == 12 && itemNumber<6)
												{
													//Sprzedarz itema
													std::shared_ptr<Merchant> t_Merch = Current_Player->Get_Merchant_status();
													if (t_Merch->Sell_Item(itemNumber+1, Current_Player->Get_Hero_status()))
													{

														dynamic_cast<MoveableUI&>(*x).SetUnActive();

														for (auto& x : interfaceUI)
														{
															if (x->whatLayer() == currentLayer && x->GetType() == "TextFieldUI")
															{
																std::string goldText = "Ilosc zlota: " + std::to_string(t_Hero->Get_Gold());
																dynamic_cast<TextFieldUI&>(*x).SetString(goldText);
															}
														}
													}
													errorLvL = 0;
												}
											}
										}
									}
								}

							}
							//ODPOWIEDNIA REAKCJA WRACA CZY NIE?
							dynamic_cast<MoveableUI&>(*x).setUnAttached();
							dynamic_cast<MoveableUI&>(*x).BackToPosition();
						}

				}
			}

			if (event.type == sf::Event::TextEntered)
			{
	
					for (auto& x : interfaceInteractiveUI[currentLayer] | std::views::filter(viewsFuncTextBoxUI))
					{
								if (x->IsUIPressed())
								{

									if (event.text.unicode < 126 && event.text.unicode >= 32)
									{
										dynamic_cast<TextBoxUI&>(*x).WriteChar(event.text.unicode);
									}

									if (event.text.unicode == 8)
									{
										dynamic_cast<TextBoxUI&>(*x).RemoveLetter();
									}
									
								}
					}
				
			}
        }



		//Dodatkowe akcjie dla Interaktywnego UI
		errorLvLtoset = false;
		for (auto& x : interfaceInteractiveUI[currentLayer])
		{

					if (x->IsUIPressed())
					{
						if (x->GetType() == "ChooseFromSetUI")
							x->SetUIColor(sf::Color::Green);
						else if (x->GetType() == "TextBoxUI")
							x->SetUIColor(sf::Color(76, 76, 76, 255));
						else if (x->GetType() == "MoveableUI")
						{
							if (dynamic_cast<MoveableUI&>(*x).GetAttached())x->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

						}
						else
							x->SetUIColor(sf::Color::Green);
					}
					else
					{
						if (x->IsMouseOn(sf::Mouse::getPosition(window)))
							if (currentLayer == 6)x->SetUIColor(sf::Color::Yellow);
							else x->SetUIColor(sf::Color(255,255,255, 100));
						else
							x->SetDefaultUIColor();
					}

					if (x->GetType() == "SlotForMUI" && x->IsMouseOn(sf::Mouse::getPosition(window)))
					{
						if (dynamic_cast<SlotForMUI&>(*x).GetFull())
						{
							errorLvLtoset = true;
							int slotNr = dynamic_cast<SlotForMUI&>(*x).GetSlotNumber();
							int setNr = dynamic_cast<SlotForMUI&>(*x).GetSetNumber();
							std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
							std::shared_ptr<Equipment> t_Equipment = t_Hero->Get_Equipment();
							
							std::stringstream ss;
							

							std::string tmpText = "";
							if (setNr == 0)
							{
								std::shared_ptr<Item> t_Item = t_Equipment->Get_Item(slotNr);
								if (t_Item != nullptr)
								{
									Statistics tmpS = t_Item->Get_Stats();
									ss << tmpS;
									tmpText = t_Item->Get_Name();
									

									if (t_Item->Get_Type() == "Weapon")
									{
										tmpText += ", Dmg: ";
										tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Item)->Get_min_Damage());
										tmpText += "-";
										tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Item)->Get_max_Damage());
									}
									tmpText += "\n" + ss.str();


									if (currentLayer == 12)tmpText += " Gold: " + std::to_string(t_Item->Get_Price());
								}
								else
								{
									errorLvLtoset = false;
								}
							}
							else if(setNr == 1)
							{
								if (currentLayer == 10)
								{
									if (slotNr == 0) {
										Statistics tmpS = t_Equipment->Get_Armor(0)->Get_Stats();
										ss << tmpS;
										tmpText = t_Equipment->Get_Armor(0)->Get_Name() + "\n" + ss.str();
									}
									else if (slotNr == 1) {
										Statistics tmpS = t_Equipment->Get_Armor(1)->Get_Stats();
										ss << tmpS;
										tmpText = t_Equipment->Get_Armor(1)->Get_Name() + "\n" + ss.str();
									}
									else if (slotNr == 2) {
										Statistics tmpS = t_Equipment->Get_Weapon()->Get_Stats();
										ss << tmpS;
										tmpText = t_Equipment->Get_Weapon()->Get_Name();
										tmpText += ", Dmg: ";
										tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Equipment->Get_Weapon())->Get_min_Damage());
										tmpText += "-";
										tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Equipment->Get_Weapon())->Get_max_Damage());


										tmpText += "\n" + ss.str();
									}
									else if (slotNr == 3) {
										Statistics tmpS = t_Equipment->Get_Armor(2)->Get_Stats();
										ss << tmpS;
										tmpText = t_Equipment->Get_Armor(2)->Get_Name() + "\n" + ss.str();
									}
								}
								else if(currentLayer ==12)
								{
									std::shared_ptr<Merchant> t_Merch = Current_Player->Get_Merchant_status();
									if (slotNr == 0) {
										Statistics tmpS = t_Merch->Get_Item(0)->Get_Stats();
										ss << tmpS;
										tmpText = t_Merch->Get_Item(0)->Get_Name();

										if (t_Merch->Get_Item(0)->Get_Type() == "Weapon")
										{
											tmpText += ", Dmg: ";
											tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Merch->Get_Item(0))->Get_min_Damage());
											tmpText += "-";
											tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Merch->Get_Item(0))->Get_max_Damage());
										}
										tmpText += "\n" + ss.str() + " Gold: " + std::to_string(t_Merch->Get_Item(0)->Get_Price() * 2);

									}
									else if (slotNr == 1) {
										Statistics tmpS = t_Merch->Get_Item(1)->Get_Stats();
										ss << tmpS;
										tmpText = t_Merch->Get_Item(1)->Get_Name();
										if (t_Merch->Get_Item(1)->Get_Type() == "Weapon")
										{
											tmpText += ", Dmg: ";
											tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Merch->Get_Item(1))->Get_min_Damage());
											tmpText += "-";
											tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Merch->Get_Item(1))->Get_max_Damage());
										}
										tmpText += "\n" + ss.str() + " Gold: " + std::to_string(t_Merch->Get_Item(1)->Get_Price() * 2);
									}
									else if (slotNr == 2) {
										Statistics tmpS = t_Merch->Get_Item(2)->Get_Stats();
										ss << tmpS;
										tmpText = t_Merch->Get_Item(2)->Get_Name();
										if (t_Merch->Get_Item(2)->Get_Type() == "Weapon")
										{
											tmpText += ", Dmg: ";
											tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Merch->Get_Item(2))->Get_min_Damage());
											tmpText += "-";
											tmpText += std::to_string(std::dynamic_pointer_cast<Weapon>(t_Merch->Get_Item(2))->Get_max_Damage());
										}
										tmpText += "\n" + ss.str() + " Gold: " + std::to_string(t_Merch->Get_Item(2)->Get_Price() * 2);
									}
								}
							}
							else if (setNr == 2)
							{
								if (currentLayer == 12)tmpText = " \t\t\t !!! Sprzedaj !!!";
							}
							itemDescription.setPosition(x->getPosition());
							itemDescription.SetString(tmpText);

						}
						else errorLvLtoset = false;
					}

					if (x->GetType() == "MoveableUI" )
					{
						std::shared_ptr<Item> t_item;
						sf::IntRect t_Rect(0, 112, 16, 16);
						if (dynamic_cast<MoveableUI&>(*x).GetSlotNumber() < 6)
						{
							std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
							std::shared_ptr<Equipment> t_Equipment = t_Hero->Get_Equipment();
							t_item = t_Equipment->Get_Item(dynamic_cast<MoveableUI&>(*x).GetSlotNumber());
							
						}
						else
						{
							
							if (currentLayer == 12)
							{
								std::shared_ptr<Merchant> t_Merch = Current_Player->Get_Merchant_status();
								t_item = t_Merch->Get_Item(dynamic_cast<MoveableUI&>(*x).GetSlotNumber() - 10);
							}
							else continue;
						}

						if (t_item != nullptr)
						{
							//Ustawienie odpowiedniej tekstury
							if (t_item->Get_Type() == "Weapon")		t_Rect = sf::IntRect(112, 48, 16, 16);
							else if (t_item->Get_Type() == "Helm")	t_Rect = sf::IntRect(112, 32, 16, 16);
							else if (t_item->Get_Type() == "Armor")	t_Rect = sf::IntRect(80, 32, 16, 16);
							else if (t_item->Get_Type() == "Gloves")t_Rect = sf::IntRect(112, 16, 16, 16);
							x->ChangeTextuerCords(t_Rect);
						}
						else
						{
							dynamic_cast<MoveableUI&>(*x).SetUnActive();

						}
					}
		}
		
		//Wyświetlanie Opisów wybranych Questów w Karczmie
		if (currentLayer == 11)
		{
			int chQuest = 1;
			for (auto& x : interfaceInteractiveUI[currentLayer] | std::views::filter(viewsFuncChooseFromandIsPressed))
			{
					chQuest = dynamic_cast<ChooseFromSetUI&>(*x).GetValue();
			}

			std::shared_ptr<Inn> t_Inn = Current_Player->Get_Inn_status();
			std::shared_ptr<Quest> t_Q1 = t_Inn->Get_First_Quest();
			std::shared_ptr<Quest> t_Q2 = t_Inn->Get_Second_Quest();
			std::shared_ptr<Quest> t_Q3 = t_Inn->Get_Third_Quest();

			std::string LONGDescp = "";

			int gettofour = 3;
			for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
			{
					if (gettofour == 0)
					{
						if(chQuest==1)LONGDescp = "Quest: " + t_Q1->Get_Description() + "\nExp: " + std::to_string(t_Q1->Get_Expirience()) + "\nGold: " + std::to_string(t_Q1->Get_Gold()) + "\nEnemy: \n" + t_Q1->Get_Opponent()->Get_Show_All();
						else if(chQuest==2)LONGDescp = "Quest: " + t_Q2->Get_Description() + "\nExp: " + std::to_string(t_Q2->Get_Expirience()) + "\nGold: " + std::to_string(t_Q2->Get_Gold()) + "\nEnemy: \n" + t_Q2->Get_Opponent()->Get_Show_All();
						else if(chQuest==3)LONGDescp = "Quest: " + t_Q3->Get_Description() + "\nExp: " + std::to_string(t_Q3->Get_Expirience()) + "\nGold: " + std::to_string(t_Q3->Get_Gold()) + "\nEnemy: \n" + t_Q3->Get_Opponent()->Get_Show_All();
						dynamic_cast<TextFieldUI&>(*x).SetString(LONGDescp);
						break;
					}
					gettofour--;
			}


		}


		//Wyświetlanie walki
		if (currentLayer == 13)
		{

			if (hits.empty())
			{
				errorLvL = 1;
			}

			if (hitTimer.getElapsedTime() >= sf::seconds(0.8f) && !hits.empty())
			{
				int hit = hits.front();
				hits.pop();
				if (heroStarts)
				{
					enemyNowHP -= hit;
				}
				else
				{
					heroNowHP -= hit;
				}
				int tmp = 0;
				int tmp2 = 0;
				std::string stmp = "-" + std::to_string(hit);

			
				for (auto& x : interfaceUI | std::views::filter(viewsFuncUIandLayer))
				{
						if (tmp2 == 2)
						{
							float t = ((float)heroNowHP / (float)heroHP) * 400.f;
							x->ChangeRightSize(t);

						}
						else if (tmp2 == 3)
						{
							float t = ((float)enemyNowHP / (float)enemyHP) * 400.f;
							x->ChangeRightSize(t);

						}
						tmp2++;
				}
				for (auto& x : interfaceUI | std::views::filter(viewsFuncTextFielUIandLayer))
				{
						if (tmp == 0 )
						{	
							if(!heroStarts) dynamic_cast<TextFieldUI&>(*x).SetString(stmp);
							else dynamic_cast<TextFieldUI&>(*x).SetString("");

						}
						else if (tmp == 1 )
						{
							if (heroStarts) dynamic_cast<TextFieldUI&>(*x).SetString(stmp);
							else dynamic_cast<TextFieldUI&>(*x).SetString("");
						}
						else if (tmp == 2)
						{
							std::string stmp = "HP: " + std::to_string(heroNowHP) + "/" + std::to_string(heroHP);
							dynamic_cast<TextFieldUI&>(*x).SetString(stmp);

						}
						else if (tmp == 3)
						{
							std::string stmp = "HP: " + std::to_string(enemyNowHP) + "/" + std::to_string(enemyHP);
							dynamic_cast<TextFieldUI&>(*x).SetString(stmp);
							break;
						}
						tmp++;
				}

				heroStarts = !heroStarts;
				hitTimer.restart();
			}
		}



		//Sprawdzenie warunku porażki (tryb Hardcore)
		if (currentLayer == 6 && Current_Player->Get_Lost())
		{
			currentLayer = 0;
			DB.Save((mainPath / "configfiles2.txt").generic_string());
		}



        window.clear();


		//Wyświetlenie tła
		if (currentLayer == 0)
		{
			BG.setTextureRect(sf::IntRect(0, 0, 1280, 720));
		}
		else if (currentLayer >= 1 && currentLayer <= 5)
		{
			BG.setTextureRect(sf::IntRect(1280*1, 720*0, 1280, 720));
		}
		else if (currentLayer == 6 )
		{
			BG.setTextureRect(sf::IntRect(1280 * 2, 720 * 0, 1280, 720));
		}
		else if (currentLayer == 7 || currentLayer == 9 || currentLayer == 10)
		{
			BG.setTextureRect(sf::IntRect(1280 * 0, 720 * 1, 1280, 720));
		}
		else if (currentLayer == 8 || (currentLayer == 13 && layerBefor == 8))
		{
			BG.setTextureRect(sf::IntRect(1280 * 3, 720 * 0, 1280, 720));
		}
		else if (currentLayer == 11)
		{
			BG.setTextureRect(sf::IntRect(1280 * 1, 720 * 1, 1280, 720));
		}
		else if (currentLayer == 12)
		{
			BG.setTextureRect(sf::IntRect(1280 * 2, 720 * 1, 1280, 720));
		}
		else if (currentLayer == 13 && layerBefor == 11)
		{
			BG.setTextureRect(sf::IntRect(1280 * 3, 720 * 1, 1280, 720));

		}
		window.draw(BG);



		int tmp_int = errorLvL;
		//UI statyczne wyświetlanie
		for (auto& x : interfaceUI)
		{

			if (x->whatLayer() == currentLayer)
				window.draw(*x);
			if (errorLvL !=0 && x->whatLayer() == -currentLayer)
			{
				if (tmp_int == 1)
				{
					window.draw(*x);
					if(currentLayer!=6)tmp_int--;
				}
				else
					tmp_int--;
			}
				
				


		}
		//UI interaktywne wyświetlanie
		for (auto& x : interfaceInteractiveUI[currentLayer])
		{
			if (x->GetType() != "MoveableUI")
					window.draw(*x);
			else if(dynamic_cast<MoveableUI&>(*x).GetActive())
				window.draw(*x);
			
			if (errorLvL != 0 && x->whatLayer() == -currentLayer)
			{
				if (tmp_int == 1)
				{
					window.draw(*x);
					if (currentLayer != 6)tmp_int--;
				}
				else
					tmp_int--;
			}
		}
		//Wyswietlenie opisu przedmiotu
		if (errorLvLtoset == true && (currentLayer == 10 || currentLayer == 12))
		{
			window.draw(itemDescription);
		}
        window.display();
    }


	//Zapisanie Gry
	DB.Save((mainPath / "configfiles2.txt").generic_string());

	//Zwolnienie zmiennych
	for (auto& x : interfaceUI)
	{
		x.release();
	}
	for (auto& ele : interfaceInteractiveUI)
	{
		for (auto& x : ele)
		{
			x.release();
		}
	}

    return 0;
}




