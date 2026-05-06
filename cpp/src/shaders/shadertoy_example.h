#pragma once

#include "shader.h"
#include "textures.h"
#include "time_manager.h"

///
/// This shader is an example of a shadertoy shader (or glsl shader) in this ASCII renderer.
/// Credit:
/// https://www.shadertoy.com/view/mtyGWy
///

class ShadertoyShader : public Shader {
public:
    ShadertoyShader() {}

    vec3 palette( float t ) const{
        vec3 a = vec3(0.5, 0.5, 0.5);
        vec3 b = vec3(0.5, 0.5, 0.5);
        vec3 c = vec3(1.0, 1.0, 1.0);
        vec3 d = vec3(0.263,0.416,0.557);

        vec3 cs = (c*t+d) * 6.28318;

        return a + b * vec3(cos(cs.x), cos(cs.y), cos(cs.z));
    }

    float fract(const float& x) const{
        return x - floorf(x);
    }

    vec2 fract(const vec2& in) const{
        return vec2(fract(in.x), fract(in.y));
    }

    vec3 fragment(const vec2& uv) const {
        vec2 uuv = ((uv * vec2(180, 100)) * 2.0 - vec2(180, 100)) / 100;
        vec2 uv0 = uuv;
        vec3 finalColor = vec3::ZERO;
        
        for (float i = 0.0; i < 4.0; i++) {
            uuv = fract(uuv * 1.5) - vec2::ONE * 0.5;

            float d = uuv.length() * exp(-uv0.length());

            d = sin(d*8. + Time::time)/8.;
            d = abs(d);

            d = pow(0.01 / d, 1.2);

            vec3 col = palette(uv0.length() + i*.4 + Time::time *.4) * d;

            finalColor = finalColor + col;
        }
            
        return finalColor;
    }
};