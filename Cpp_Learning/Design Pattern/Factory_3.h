#pragma once
#include <string>
#include <map>

// One change is that I have removed our enum class
// This is because during run-time I want to be able to create different types
// Add type of function before so we can make 

class IGameObject {};

template<typename IType, auto CreationFunction>
class MyGameObjectFactory {

public:
	using object_type = IType;
	using creation_type = decltype(CreationFunction);

	// Register a new user created object type
	// Again we also have to pass to how to 'create an object'
	static void RegisterObject(const std::string& type, creation_type cb) {
		s_Objects[type] = cb;
	}

	// Unregister a user created object type
	// Remover from our map
	static void UnregisterObject(const std::string& type) {
		s_Objects.erase(type);
	}

	// Our previous 'factory method'
	//
	template<typename...Ts>
	static object_type* CreateSingleObject(const std::string& type, Ts...args) {

		auto it = s_Objects.find(type);

		if (it != s_Objects.end()) {
			// Call the callback function
			return (it->second)(args...);
		}

		return nullptr;
	}



private:
	// Convenience type definition
	using CallBackMap = std::map<std::string, creation_type>;

	// Map of all different objects that we can create
	static CallBackMap s_Objects;
};

template<typename IType, typename CreationFunction>
MyGameObjectFactory<IType, CreationFunction>::CallBackMap
MyGameObjectFactory<IType, CreationFunction>::s_Objects;