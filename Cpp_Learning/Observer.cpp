#include <iostream>
#include <map>
#include <list>
#include <forward_list>

class IObserver {
public:
	virtual void OnNotify() = 0;
	virtual ~IObserver() = default;
};


class ISubject {

public:

	ISubject() = default;
	virtual ~ISubject() = default;

	virtual void AddObserver(IObserver* observer)
	{
		m_Observers.push_front(observer);
	}

	virtual void RemoveObserver(IObserver* observer)
	{
		m_Observers.remove(observer);
		std::cout << observer << " is removed.\n";
	}

	void NotifyAll()
	{
		for (auto e : m_Observers) e->OnNotify();
	}

	void Notify(int message) {}

private:
	using ObserverList = std::forward_list<IObserver*>;

	ObserverList  m_Observers;
};


class Watcher : public IObserver {
public:
	// We Will automatical register to object subject
	explicit Watcher(ISubject* subject, const std::string& msg) 
		:m_Subject(subject), m_msg(msg)
	{
		m_Subject->AddObserver(this);
	}

	void OnNotify() override {
		std::cout << "message : " << m_msg << '\n';
	}

	~Watcher() {
		m_Subject->RemoveObserver(this);
	}

private:
	ISubject*   m_Subject;
	std::string m_msg;
};






int main() {

	ISubject subject;

	Watcher  w1(&subject, "wchater 1");
	Watcher  w2(&subject, "watcher 2");

	subject.NotifyAll();

	return 0;
}