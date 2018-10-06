#ifndef TYPE_DEFS_H
#define TYPE_DEFS_H

#include <vector>
#include <gmp.h>

#if __cplusplus >= 201103L
#include <cstdint>

// take advantage of C++11 using decl to improve readability
using byte = uint8_t;
using mpz_t_arr = __mpz_struct**;
using PrivateKey = uint32_t*;
using SomewhatPublicKey = __mpz_struct**;
using SomewhatPrivateKey = mpz_t;

struct PublicKey {
	SomewhatPublicKey old_key;
	SomewhatPublicKey old_key_extra;
	mpz_t_arr y_vector;
};

struct CipherBit {
	mpz_t old_ciphertext;
	uint64_t* z_vector; // originally unsigned long but that can change based off of target
};

#else
// this was not defined
typedef unsigned char byte;

/* struct KeyStruct { */
/*   PrivateKey sk; */
/*   PublicKey pk; */
/* }; */

/* typedef struct KeyStruct Key; */

typedef __mpz_struct** mpz_t_arr;

// Indicator vector of elements in public key which
// are part of the private key
typedef unsigned int* PrivateKey;

// Definitions of keys in the somewhat homomorphic scheme
typedef __mpz_struct** SomewhatPublicKey;
typedef mpz_t SomewhatPrivateKey;

struct PublicKeyStruct {
  SomewhatPublicKey old_key;
  SomewhatPublicKey old_key_extra; // Extra elements for optimization from section 3.3.1
  mpz_t_arr y_vector;
};

typedef struct PublicKeyStruct PublicKey;

struct CipherBitStruct {
  mpz_t old_ciphertext;
  unsigned long* z_vector;
};
typedef struct CipherBitStruct CipherBit;

#endif 


#endif //TYPE_DEFS_H
