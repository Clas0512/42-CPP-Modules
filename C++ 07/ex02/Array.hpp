#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private:
        T* mainArray;
        unsigned int arraySize;
	public:
		Array(void) {
			mainArray = new T[0];
			arraySize = 0;
		}
		~Array(void) {
			std::cout << "Default Destructor Call" << std::endl;
    		delete[] mainArray;
		}
        Array(unsigned int n)
		{
			arraySize = n;
			if (n > 0)
				mainArray = new T[n];
			else
				mainArray = nullptr;
		}
		Array(const Array &copy){
			this->mainArray = nullptr;
			*this = copy;
		}
		Array &operator=(const Array &rhs) {
    		if (this != &rhs) {
				if (this->mainArray != nullptr)
					delete[] mainArray;
        		arraySize = rhs.arraySize;
        		if (arraySize > 0) {
            		mainArray = new T[arraySize];
            		for (unsigned int i = 0; i < arraySize; ++i)
                		mainArray[i] = rhs.mainArray[i];
        		} 
				else
            		mainArray = nullptr;
    		}
    		return *this;
		}
		class outOfBound : public std::exception{
			public:
				virtual const char* what() const throw(){
					return ("Out of bound!");
				};
		};
		T& operator[](unsigned int n) {
    		if (n >= this->arraySize || n < 0)
				throw outOfBound();
    		return (mainArray[n]);
		}
		unsigned int size(void) {
			return arraySize;
		}
};

#endif