#pragma once
#include <array>
#include <bitset>
#include <iostream>

class Entity;
class Component;

using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
	static ComponentID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentID getComponentID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value, "none");
	static const ComponentID typeID = getComponentID();
	return typeID;
}

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<Component*, MAX_COMPONENTS>;