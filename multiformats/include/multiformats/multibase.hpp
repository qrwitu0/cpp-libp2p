

#include <vector>
#include <string>
#include <unordered_map>


namespace libp2p {
   namespace multiformats {


      using byte_array = std::vector<uint8_t>;


      using std::string;


      enum class Encoding : char {
         Identity          = 0x00,
         Base2             = '0',
         Base16            = 'f',
         Base16Upper       = 'F',
         Base32hex         = 'v',
         Base32hexUpper    = 'V',
         Base32hexPad      = 't',
         Base32hexPadUpper = 'T',
         Base32            = 'b',
         Base32Upper       = 'B',
         Base32pad         = 'c',
         Base32padUpper    = 'C',
         Base58Flickr      = 'Z',
         Base58BTC         = 'z',
         Base64            = 'm',
         Base64pad         = 'M',
         Base64url         = 'u',
         Base64urlPad      = 'U'
      };

      std::unordered_map<string,char> encodings = {
            {"identity",         0x00},
            {"base2",             '0'},
            {"base16",            'f'},
            {"base16upper",       'F'},
            {"base32hex",         'v'},
            {"base32hexupper",    'V'},
            {"base32hexpad",      't'},
            {"base32hexpadupper", 'T'},
            {"base32",            'b'},
            {"base32upper",       'B'},
            {"base32pad",         'c'},
            {"base32padupper",    'C'},
            {"base58flickr",      'Z'},
            {"base58btc",         'z'},
            {"base64",            'm'},
            {"base64pad",         'M'},
            {"base64url",         'u'},
            {"base64urlpad",      'U'},
      };

      std::unordered_map<char,string> encoding_to_string {
            {0x00,   "identity"},
            {'0',    "base2"},
            {'f',    "base16"},
            {'F',    "base16upper"},
            {'v',    "base32hex"},
            {'V',    "base32hexupper"},
            {'t',    "base32hexpad"},
            {'T',    "base32hexpadupper"},
            {'b',    "base32"},
            {'B',    "base32upper"},
            {'c',    "base32pad"},
            {'C',    "base32padupper"},
            {'Z',    "base58flickr"},
            {'z',    "base58btc"},
            {'m',    "base64"},
            {'M',    "base64pad"},
            {'u',    "base64url"},
            {'U',    "base64urlpad"},
      };



      class multibase {
      public:
         static std::string encode(encoding base, const byte_array& bytes) const;

         static std::string decode(std::string_view str) const;

      };



   }
}

