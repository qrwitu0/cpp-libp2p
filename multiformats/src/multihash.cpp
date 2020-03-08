
#include "../include/multiformats/multihash.hpp"


namespace multiformats::multihash {

   std::map<string,uint64_t> name_to_code;
   std::map<uint64_t,string> code_to_name;
   std::map<uint64_t,int> default_lenght;

   int init(){

      name_to_code = {
            {"identity",      identity},
            {"sha1",          sha1},
            {"sha2-256",      sha2_256},
            {"sha2-512",      sha2_512},
            {"sha3-512",      sha3_512},
            {"sha3-384",      sha3_384},
            {"sha3-256",      sha2_256},
            {"sha3-224",      sha3_224},
            {"shake-128",     shake_128},
            {"shake-256",     shake_256},
            {"keccak-224",    keccak_224},
            {"keccak-256",    keccak_256},
            {"keccak-384",    keccak_384},
            {"keccak-512",    keccak_512},
            {"murmur3-128",   murmur3_128},
            {"dbl_sha2-256",  dbl_sha2_256},
            {"x11",           x11},
            {"md5",           md5}
      };

      code_to_name = {
            {identity,      "identity"},
            {sha1,          "sha1"},
            {sha2_256,      "sha2-256"},
            {sha2_512,      "sha2-512"},
            {sha3_512,      "sha3-512"},
            {sha3_384,      "sha3-384"},
            {sha3_256,      "sha2-256"},
            {sha3_224,      "sha3-224"},
            {shake_128,     "shake-128"},
            {shake_256,     "shake-256"},
            {keccak_224,    "keccak-224"},
            {keccak_256,    "keccak-256"},
            {keccak_384,    "keccak-384"},
            {keccak_512,    "keccak-512"},
            {murmur3_128,   "murmur3-128"},
            {dbl_sha2_256,  "dbl-sha2-256"},
            {x11,           "x11"},
            {md5,           "md5"}
      };

      // DefaultLengths maps a hash code to it's default length
      default_lenght = {
            {identity,     -1},
            {sha1,         20},
            {sha2_256,     32},
            {sha2_512,     64},
            {sha3_512,     64},
            {sha3_384,     48},
            {sha3_256,     32},
            {sha3_224,     28},
            {shake_128,    32},
            {shake_256,    64},
            {keccak_224,   28},
            {keccak_256,   32},
            {keccak_384,   48},
            {keccak_512,   64},
            {murmur3_128,  4},
            {dbl_sha2_256, 32},
            {x11,          64},
            {md5,          16},
      }


      for(uint64_t c = code::blake2b_min; c <= code::blake2b_max; ++c){
            auto n = c - code::blake2b_min + 1;
            auto name = std::string("blake2b-") + std::to_string(n*8);
            name_to_code[name] = c;
            code_to_name[c] = name;
            default_lenght[c] = int(n);
      }

      for(uint64_t c = code::blake2s_min; c <= code::blake2s_max; ++c){
            auto n = c - code::blake2s_min + 1;
            auto name = std::string("blake2s-") + std::to_string(n*8);
            name_to_code[name] = c;
            code_to_name[c] = name;
            default_lenght[c] = int(n);
      }

   }
   auto _ = init();




}