#pragma once

template <typename Type1, typename Type2>
class MinClass
{
public:

	Type1 num1_;
	Type2 num2_;

	MinClass(Type1 num1, Type2 num2) : num1_(num1), num2_(num2){}

	Type1 Min() {
		if (num1_ < num2_) {
			return static_cast<Type1>(num1_);
		} else {
			return static_cast<Type1>(num2_);
		}
	}
	
};
