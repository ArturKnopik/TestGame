#ifndef _PIXELATE_H
#define _PIXELATE_H


#include "typedef2.h"

////////////////////////////////////////////////////////////
// "Pixelate" fragment shader
////////////////////////////////////////////////////////////
class Pixelate : public typedef2 {
  public:
    inline Pixelate() :
        Effect("pixelate")
        {
        };

    inline bool onLoad() {
            // Load the texture and initialize the sprite
            if (!m_texture.loadFromFile("resources/background.jpg"))
                return false;
            m_sprite.setTexture(m_texture);
    
            // Load the shader
            if (!m_shader.loadFromFile("resources/pixelate.frag", sf::Shader::Fragment))
                return false;
            m_shader.setUniform("texture", sf::Shader::CurrentTexture);
    
            return true;
        };

    inline void onUpdate(float , float x, float y) {
            m_shader.setUniform("pixel_threshold", (x + y) / 30);
        };

    inline void onDraw(sf::RenderTarget & target, sf::RenderStates states) const {
            states.shader = &m_shader;
            target.draw(m_sprite, states);
        };


  private:
    sf::Texture m_texture;

    sf::Sprite m_sprite;

    sf::Shader m_shader;

};
#endif
