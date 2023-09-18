#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>
#include <cryptopp/channels.h>
#include <cryptopp/filters.h>

int main()
{
    using namespace CryptoPP;

    SHA1 hash;

    std::cout<<"Name: "<<hash.AlgorithmName()<<std::endl;
    std::cout<<"Digest size: "<<hash.DigestSize()<<std::endl;
    std::cout<<"Block size: "<<hash.BlockSize()<<std::endl;

    std::string msg;

    std::string way="/home/artem/Practica/text";

    std::ifstream file;
    file.open(way);
    if (!file.good()) {
        std::cout<<"Ошибка открытия файла"<<std::endl;
        exit(1);
    }
    
    while (true) {
        file>>msg;
        if ( file.eof()) {
            break;
        }
    }

    std::vector<byte> digest(hash.DigestSize());

    hash.Update((const byte*)msg.data(), msg.size());
    hash.Final(digest.data());

    std::cout<<"Message: "<<msg<<std::endl;
    std::cout<<"Digest: ";
    StringSource(digest.data(), digest.size(), true,
                 new HexEncoder(new FileSink(std::cout)));
    std::cout<<std::endl;
    return 0;

}