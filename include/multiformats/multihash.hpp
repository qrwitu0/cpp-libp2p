
#include <string>
#include <vector>

namespace libp2p::multiformats {




   class multihash {

   };




   enum class hash_type : uint64_t {
      IDENTITY    = 0x00,
      SHA1        = 0x11,
      SHA2_256    = 0x12,
      SHA2_512    = 0x13,
      SHA3_512    = 0x14,
      SHA3_384    = 0x15,
      SHA3_256    = 0x16,
      SHA3_224    = 0x17,
      SHAKE_128   = 0x18,
      SHAKE_256   = 0x19,
      KECCAK_224  = 0x1A,
      KECCAK_256  = 0x1B,
      KECCAK_384  = 0x1C,
      KECCAK_512  = 0x1D,

      BLAKE2B_MIN = 0xb201,
      BLAKE2B_MAX = 0xb240,
      BLAKE2S_MIN = 0xb241,
      BLAKE2S_MAX = 0xb260,

      MD5         = 0xd5,

      DBL_SHA2_256 = 0x56,

      MURMUR3_128 = 0x22,
      // Deprecated: use MURMUR3_128
            MURMUR3 = MURMUR3_128

      X11 = 0x1100

      SHA3       = SHA3_512,


   };

   using multihash = std::vector<uint8_t>;


   struct decoded_multihash {
      uint64_t             code;
      size_t               size;
      std::vector<uint8_t> digest;
   };

   class multihash




   std::string multihash_to_hexstring(multihash mh);
   std::string multihash_to_string(multihash mh);
   multihash multihash_from_hexstring(std::string str);
   std::string to_base58_string();
   std::string form_base58_string();

   decode();
   encode();



}