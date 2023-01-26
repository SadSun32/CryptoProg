#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    using namespace CryptoPP;
	string digest;
    Weak::MD5 hash; //функция-заглушка
    FileSource("test", true, new HashFilter(hash, new HexEncoder(new StringSink (digest)))); //преобразуем в PHP, с возможностью редактирования
    cout<<"Hash: "<< digest << endl;
    return 0;
}