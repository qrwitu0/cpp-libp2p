


#include <optional>
#include <vector>
#include <string>
#include <libp2p/utils/span.hpp>


namespace libp2p { namespace multiformats {


      class unsigned_varint {

         explicit unsigned_varint(uint64_t number);

         explicit unsigned_varint(nonstd::span<const uint8_t> bytes);

         static std::optional<unsigned_varint> create(nonstd::span<const uint8_t> bytes);

         uint64_t to_uint64() const;

         nonstd::span<const uint8_t> to_bytes() const;

         std::string to_hex() const;

         bool operator==(const unsigned_varint& r) const;
         bool operator!=(const unsigned_varint& r) const;
         bool operator<(const unsigned_varint& r) const;


         size_t size() const;

         static size_t valid_length(nonstd::span<const uint8_t> bytes);

      private:
         std::vector<uint8_t> store_bytes;
      };


   }
}