
#include <string>
#include <vector>

namespace multiformats::multihash {

   enum code : uint64_t {
      identity     = 0x00,
      sha1         = 0x11,
      sha2_256     = 0x12,
      sha2_512     = 0x13,
      sha3_512     = 0x14,
      sha3_384     = 0x15,
      sha3_256     = 0x16,
      sha3_224     = 0x17,
      shake_128    = 0x18,
      shake_256    = 0x19,
      keccak_224   = 0x1A,
      keccak_256   = 0x1B,
      keccak_384   = 0x1C,
      keccak_512   = 0x1D,

      murmur3_128  = 0x22,

      dbl_sha2_256 = 0x56,

      x11          = 0x1100,

      blake2b_min  = 0xb201,
      blake2b_max  = 0xb240,
      blake2s_min  = 0xb241,
      blake2s_max  = 0xb260,

      md5          = 0xd5,
   };


   extern std::map<string,uint64_t> name_to_code;
   extern std::map<uint64_t,string> code_to_name;
   extern std::map<uint64_t,int> default_lenght;




   using multihash_type = std::vector<uint8_t>;

   struct decoded_multihash {
      uint64_t             code;
      size_t               size;
      std::vector<uint8_t> digest;
   };



   class multihash {
   public:


      encode();

      decode();







   };








   std::string multihash_to_hexstring(multihash mh);
   std::string multihash_to_string(multihash mh);
   multihash multihash_from_hexstring(std::string str);
   std::string to_base58_string();
   std::string form_base58_string();

   decode();
   encode();



}

