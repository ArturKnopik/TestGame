#ifndef _STORMBLINK_H
#define _STORMBLINK_H


#include "typedef2.h"

////////////////////////////////////////////////////////////
// "Storm" vertex shader + "blink" fragment shader
////////////////////////////////////////////////////////////
class StormBlink : public typedef2 {
  public:
    inline StormBlink() :
        Effect("storm + blink")
        {
        };

    inline bool onLoad() {
            // Create the points
            m_points.setPrimitiveType(sf::Points);
            for (int i = 0; i < 40000; ++i)
            {
                float x = static_cast<float>(std::rand() % 800);
                float y = static_cast<float>(std::rand() % 600);
                sf::Uint8 r = std::rand() % 255;
                sf::Uint8 g = std::rand() % 255;
                sf::Uint8 b = std::rand() % 255;
                m_points.append(sf::Vertex(sf::Vector2f(x, y), sf::Color(r, g, b)));
            }
    
            // Load the shader
            if (!m_shader.loadFromFile("resources/storm.vert", "resources/blink.frag"))
                return false;
    
            return true;
        };

    inline void onUpdate(float time, float x, float y) {
            float radius = 200 + std::cos(time) * 150;
            m_shader.setUniform("storm_position", sf::Vector2f(x * 800, y * 600));
            m_shader.setUniform("storm_inner_radius", radius / 3);
            m_shader.setUniform("storm_total_radius", radius);
            m_shader.setUniform("blink_alpha", 0.5f + std::cos(time * 3) * 0.25f);
        };

    inline void onDraw(sf::RenderTarget & target, sf::RenderStates states) const {
            states.shader = &m_shader;
            target.draw(m_points, states);
        };


  private:
    sf::VertexArray m_points;

    sf::Shader m_shader;

};
#endif
