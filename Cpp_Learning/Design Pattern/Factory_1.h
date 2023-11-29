#pragma once
#include <string>
#include <map>

// One change is that I have removed our enum class
// This is because during run-time I want to be able to create different types

class IGameObject{};

template<typename IType>
class MyGameObjectFactory {

public:
	// Callback function for creating an object
	 using CreateObjectCallback = IType *(*)();

	// Register a new user created object type
	// Again we also have to pass to how to 'create an object'
	static void RegisterObject(const std::string& type, CreateObjectCallback cb) {
		s_Objects[type] = cb;
	}

	// Unregister a user created object type
	// Remover from our map
	static void UnregisterObject(const std::string& type) {
		s_Objects.erase(type);
	}

	// Our previous 'factory method'
	//
	static IType* CreateSingleObject(const std::string& type) {

		 auto it = s_Objects.find(type);

		if (it != s_Objects.end()) {
			// Call the callback function
			return (it->second)();
		}

		return nullptr;
	}



private:
	// Convenience type definition
	using CallBackMap = std::map<std::string, CreateObjectCallback>;

	// Map of all different objects that we can create
	static CallBackMap s_Objects;
};

template<typename IType>
MyGameObjectFactory<IType>::CallBackMap MyGameObjectFactory<IType>::s_Objects;