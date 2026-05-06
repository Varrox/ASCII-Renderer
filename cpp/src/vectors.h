#pragma once

#include <math.h>

struct vec3{
    float x, y, z;
    
    constexpr vec3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : x(_x), y(_y), z(_z) {}

    inline float squared_length() const{
        return square_magnitude(*this);
    }

    inline float length() const{
        return magnitude(*this);
    }

    inline vec3 normalized() const{
        return normalize(*this);
    }

    inline vec3 rotated(vec3 axis, float angle) const{
        axis = axis.normalized();
    
        double cosA = cos(angle), sinA = sin(angle);
        
        return *this * cosA + cross(axis, *this) * sinA + axis * (dot(axis, *this) * (1.0 - cosA));
    }

    static constexpr float square_magnitude(const vec3& x){
        return x.x * x.x + x.y * x.y + x.z * x.z;
    }

    static inline float magnitude(const vec3& x){
        return sqrt(square_magnitude(x));
    }

    static inline vec3 normalize(vec3 x){
        float length = magnitude(x);
        return {x.x / length, x.y / length, x.z / length};
    }

    static inline float distance(const vec3& lhs, const vec3& rhs){
        return sqrt(square_magnitude(lhs - rhs));
    }

    static constexpr float dot(vec3 lhs, vec3 rhs){
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static constexpr vec3 cross(vec3 lhs, vec3 rhs){
        return {lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x};
    }

    static constexpr vec3 lerp(vec3 a, vec3 b, float t){
        return a + (b - a) * t;
    }

    constexpr vec3 operator+(const vec3& other) const{
        return {x + other.x, y + other.y, z + other.z};
    }

    constexpr vec3 operator-(const vec3& other) const{
        return {x - other.x, y - other.y, z - other.z};
    }

    constexpr vec3 operator-() const {
        return {-x, -y, -z};
    }

    constexpr vec3 operator*(const vec3& other) const{
        return {x * other.x, y * other.y, z * other.z};
    }

    constexpr vec3 operator*(float scalar) const{
        return {x * scalar, y * scalar, z * scalar};
    }

    constexpr vec3 operator/(float scalar) const{
        return {x / scalar, y / scalar, z / scalar};
    }

    static const vec3 ZERO;
    static const vec3 ONE;
    static const vec3 RIGHT;
    static const vec3 LEFT;
    static const vec3 UP;
    static const vec3 DOWN;
    static const vec3 FORWARD;
    static const vec3 BACKWARD;
};

inline constexpr vec3 vec3::ZERO = {0.0f, 0.0f, 0.0f};
inline constexpr vec3 vec3::ONE = {1.0f, 1.0f, 1.0f};
inline constexpr vec3 vec3::RIGHT = {1.0f, 0.0f, 0.0f};
inline constexpr vec3 vec3::LEFT = {-1.0f, 0.0f, 0.0f};
inline constexpr vec3 vec3::UP = {0.0f, 1.0f, 0.0f};
inline constexpr vec3 vec3::DOWN = {0.0f, -1.0f, 0.0f};
inline constexpr vec3 vec3::FORWARD = {0.0f, 0.0f, 1.0f};
inline constexpr vec3 vec3::BACKWARD = {0.0f, 0.0f, -1.0f};

struct vec2 {
    float x = 0.0, y = 0.0;
    
    constexpr vec2(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y) {}

    inline float squared_length() const{
        return square_magnitude(*this);
    }

    inline float length() const{
        return magnitude(*this);
    }

    inline vec2 normalized() const{
        return normalize(*this);
    }

    inline vec2 rotated(float radians) const{
        float c = cos(radians), s = sin(radians);
        return {c * y - s * x, s * y + c * x};
    }

    static constexpr float square_magnitude(const vec2& x){
        return x.x * x.x + x.y * x.y;
    }

    static inline float magnitude(const vec2& x){
        return sqrt(square_magnitude(x));
    }

    static inline vec2 normalize(vec2 x){
        float length = magnitude(x);
        return {x.x / length, x.y / length};
    }

    static inline float distance(const vec2& lhs, const vec2& rhs){
        return sqrt(square_magnitude(lhs - rhs));
    }

    static constexpr float dot(vec2 lhs, vec2 rhs){
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    static constexpr float cross(vec2 lhs, vec2 rhs){
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    static constexpr vec2 lerp(vec2 a, vec2 b, float t){
        return a + (b - a) * t;
    }
    
    constexpr vec2 operator+(const vec2& other) const{
        return {x + other.x, y + other.y};
    }
    
    constexpr vec2 operator-(const vec2& other) const{
        return {x - other.x, y - other.y};
    }
    
    constexpr vec2 operator-() const {
        return {-x, -y};
    }
    
    constexpr vec2 operator*(const vec2& other) const{
        return {x * other.x, y * other.y};
    }
    
    constexpr vec2 operator*(float scalar) const{
        return {x * scalar, y * scalar};
    }
    
    constexpr vec2 operator/(float scalar) const{
        return {x / scalar, y / scalar};
    }

    static const vec2 ZERO;
    static const vec2 ONE;
    static const vec2 RIGHT;
    static const vec2 LEFT;
    static const vec2 UP;
    static const vec2 DOWN;
};

inline constexpr vec2 vec2::ZERO = {0.0, 0.0};
inline constexpr vec2 vec2::ONE = {1.0, 1.0};
inline constexpr vec2 vec2::RIGHT = {1.0, 0.0};
inline constexpr vec2 vec2::LEFT = {-1.0, 0.0};
inline constexpr vec2 vec2::UP = {0.0, 1.0};
inline constexpr vec2 vec2::DOWN = {0.0, -1.0};