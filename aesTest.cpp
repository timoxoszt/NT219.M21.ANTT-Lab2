#include <iostream>
#include <iomanip>

#include "cryptopp/modes.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"

int main(int argc, char* argv[]) {

    byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );

    //
    // String and Sink setup
    //
    std::string plaintext = "Tra My ";
    std::string ciphertext;
    std::string decryptedtext;

    //
    // Dump Plain Text
    //
    std::cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    std::cout << plaintext;
    std::cout << std::endl << std::endl;

    //
    // Create Cipher Text
    //
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption( aesEncryption, iv );

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink( ciphertext ) );
    stfEncryptor.Put( reinterpret_cast<const unsigned char*>( plaintext.c_str() ), plaintext.length() + 1 );
    stfEncryptor.MessageEnd();

    //
    // Dump Cipher Text
    //
    std::cout << "Cipher Text (" << ciphertext.size() << " bytes)" << std::endl;

    for( int i = 0; i < ciphertext.size(); i++ ) {

        std::cout << "0x" << std::hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
    }

    std::cout << std::endl << std::endl;

    //
    // Decrypt
    //
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption( aesDecryption, iv );

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( decryptedtext ) );
    stfDecryptor.Put( reinterpret_cast<const unsigned char*>( ciphertext.c_str() ), ciphertext.size() );
    stfDecryptor.MessageEnd();

    //
    // Dump Decrypted Text
    //
    std::cout << "Decrypted Text: " << std::endl;
    std::cout << decryptedtext;
    std::cout << std::endl << std::endl;

    return 0;
}
