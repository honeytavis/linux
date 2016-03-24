#include <pthread.h>
#include <iostream>

class InfoPrinted {
public:
	InfoPrinted(char c, int n) : _c(c), _n(n) {}
	void Show() const
	{
		for(int i = 0; i < _n; i++) {
			std::cerr << _c; 
		}
		std::cerr << '\n'; 
	}

private:
	char _c; 
	int _n; 
}; 

void* PrintInfo(void* info)
{
/// InfoPrinted* p = reinterpret_cast<InfoPrinted*>(info); 
	InfoPrinted* p = static_cast<InfoPrinted*>(info); 
	if (p) {
		p->Show(); 
	}
	return NULL; 
}

int main()
{
	pthread_t tid1, tid2; 
	InfoPrinted* p = new InfoPrinted('a', 20); 
	pthread_create(&tid1, NULL, &PrintInfo, reinterpret_cast<void*>(p)); 
	InfoPrinted* q = new InfoPrinted('z', 20); 
	pthread_create(&tid2, NULL, &PrintInfo, reinterpret_cast<void*>(q)); 

/// 等待子线程结束
	pthread_join(tid1, NULL); 
	pthread_join(tid2, NULL); 

	return 0; 
}
