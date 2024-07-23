#include <SFML/Graphics.hpp>
export module GraphicElement;

export class GraphicElement : public sf::Drawable, public sf::Transformable
{
public:
protected:
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};