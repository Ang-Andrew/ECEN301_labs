#include <t89c51ac3.h>

unsigned char ReadInput()
{
	static unsigned char Input;
	Input = P2;
	return Input;
}

void main()
{
	P1 = ReadInput();

}