all:
	g++ ./public_judge.cpp -o submit -lcrypto -std=c++0x
	g++ ./crypt.cpp -o 1keycrypt -lcrypto -std=c++0x
clean:
	rm -f submit 1keycrypt

