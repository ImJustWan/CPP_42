#include <iostream>

template< typename T>
class List {
	public:
		List<T>(T const &content){
		}

		List<T>(List<T> const &list){
		}

		~List<T>(){
		}
	
	private:
		T		_content;
		List<T>	*next;
};

int main() {
	List<int>			a(42);
	List<float>			b(3.14f);
	List< List< int > >	c(a);

	return 0;
}