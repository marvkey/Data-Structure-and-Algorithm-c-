#include<iostream>
#include <vector>
#include <memory>
class Temp {
public:

	static std::string GetName() {
		return "Temp";
	}
	uint16_t height = 0;
};

class Temp2: public Temp {
public:
	/*
	static std::string GetName() {
		return "Temp2";
	}
	*/
};
int main() {
	std::vector<Temp>vectors;
	vectors.push_back(Temp());
	vectors.push_back(Temp2());
	for (Temp gg : vectors) {
		std::cout << gg.GetName() << std::endl;
	}
}