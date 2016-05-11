/*
 * A Singleton and optimize
 *
 */

#include <iostream>
using namespace std;

//class Singleton//existing thread safety problem
//{
//private:
//	Singleton(){}
//	static Singleton* m_ptr;
//public:
//	static Singleton* GetInstance()
//	{
//		m_ptr = new Singleton();
//		return m_ptr;
//	}
//};
class lockd
{
	friend class Singleton;
private:
	CRITION_SECTION _cs;
public:
	lockd()
	{::InitializeCriticalSection(&_cs);}
	void lock()
	{::EnterCriticalSection(&_cs);}
	void unlock()
	{::LeaveCriticalSection(&_cs);}
	~lockd()
	{::DeleterCriticalSection(&_cs);}
};
class Singleton//existing thread safety problem
{
private:
	Singleton(){}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	static Singleton* m_ptr;
	
public:
	static Singleton* GetInstance()
	{
		if(m_ptr == NULL)
		{
			lockd* mutex = new lockd();
			mutex->lock(); //resolve thread safety 
			if(m_ptr ==NULL)
			{
				m_ptr = new Singleton();
				return m_ptr;
			}
		}
	}
//		static Singleton* GetInstance()
//		{
//			static Sigleton m_ptr;
//			return &m_ptr;
//		}
};
int main()
{
	Singleton* p1 = GetInstance();
	Singleton* p2 = p1->GetInstance();

	return 0
}
