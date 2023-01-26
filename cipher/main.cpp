#include <string>
#include <iostream>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/cbcmac.h>
using namespace std;
using namespace CryptoPP;

int main(){
    ifstream text1;
    ofstream text2;
    ifstream text3;
    string str;
    string str1 = "";
    string file;
    int n;
    {
        cout << "Encrypt - 0; Decrypt- 1 ";
        cin >> n;
        if (n == 0) {
            string str;
            string str1 = "";
            string file;
            cout << "Text file:";
            cin >> file;
            ifstream text1 (file);
            char c;
            while (text1.get(c)) 
            {
                str1.push_back(c);
            }
            byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];//задаем ключ
            memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);// не должно работать
            memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
            string text = str1;
            string ciphertext;
            CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);//объект-зашифровщик
            CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);//блочное шифрование
            CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));//pipelining
            stfEncryptor.Put(reinterpret_cast<const unsigned char*>(text.c_str()), text.length());//обрабатываем текст
            stfEncryptor.MessageEnd();//TODO
            cout << "Output file: ";
            string file2;
            cin >> file2;
            ofstream text2 (file2);
            for (int i = 0; i < ciphertext.size(); i++) 
            {
                text2 << ciphertext[i];
            }
        }
        else  if (n == 1) 
        {
            string str;
            string str1 = "";
            string file;
            cout << "Input file: ";
            cin >> file;
            ifstream text1 (file);
            char c;
            while (text1.get(c)) 
            {
                str1.push_back(c);
            }
            byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
            memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
            memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
            string text = str1;
            string decryptedtext;
            string file2;
            cout << "Output file: ";
            cin >> file2;
            ofstream text2 (file2);
            ifstream text3 (file2);
            CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
            CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
            CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
            stfDecryptor.Put(reinterpret_cast<const unsigned char*>(text.c_str()), text.size());
            stfDecryptor.MessageEnd();
            text2 << decryptedtext;
        }
        else return 0;
    }return 0;
}