#pragma once

//   Exemple for static member in interface or abstract class


namespace exemple {

	class IDrawable {
		static int ID_ref ;
		int _id;
	public:
		virtual void draw() const = 0;

		static int get_IDRef() {
			ID_ref++;
			return ID_ref;
		}

		void set_ID() {
			//setting increamental id for every class
			// should all different 
			_id = 1 + exemple::IDrawable::get_IDRef();
		}

		int get_id() const {
			return _id;
		}

		virtual ~IDrawable() = default;

	};

	int IDrawable::ID_ref = 0;

}