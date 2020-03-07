

#include <libp2p/multiformats/unsigned_varint.hpp>


namespace libp2p {
   namespace multiformats{


      unsigned_varint::unsigned_varint(uint64_t number) {
         do {
            uint8_t byte = static_cast<uint8_t>(number) & 0x7F;
            number >>= 7;
            if (number != 0)
               byte |= 0x80;
            store_bytes.push_back(byte);
         } while (number != 0);
      }

      unsigned_varint::unsigned_varint(nonstd::span<const uint8_t> bytes):
      store_bytes(bytes.begin(),bytes.begin() + valid_length(bytes)){}


      std::optional<unsigned_varint> unsigned_varint::create(nonstd::span<const uint8_t> bytes){
         size_t size = valid_length(bytes);
         if(size > 0){
            return unsigned_varint(bytes);
         }
         return {};
      }


      uint64_t unsigned_varint::to_uint64() const {
         uint64_t res = 0;
         size_t shift = 0;
         for( const auto& byte : store_bytes ){
            res += static_cast<uint64_t>(byte & 0x7f) << shift;
            shift += 7;
         }
         return res;
      }


      nonstd::span<const uint8_t> unsigned_varint::to_bytes() const{
         return nonstd::span(store_bytes.data(),store_bytes.size());
      }

      std::string unsigned_varint::to_hex() const {
         return std::string();
      }

      bool unsigned_varint::operator==(const unsigned_varint& r) const {
         return false;
      }

      bool unsigned_varint::operator!=(const unsigned_varint& r) const {
         return false;
      }

      bool unsigned_varint::operator<(const unsigned_varint& r) const {
         return false;
      }

      size_t unsigned_varint::size() const {
         return store_bytes.size();
      }

      size_t unsigned_varint::valid_length(nonstd::span<const uint8_t> bytes){
         size_t size = 0;
         size_t shift = 0;
         size_t tail_zero_bytes = 0;
         constexpr size_t capacity = sizeof(uint64_t) * 8;

         for(const auto& byte : bytes){
            uint64_t slice = byte & 0x7f;

            if(slice == 0)
               ++tail_zero_bytes;
            else
               tail_zero_bytes = 0;

            if( shift >= capacity || slice << shift >> shift != slice ){
               size = 0;
               break;
            }
            if((byte & 0x80) == 0){
               break;
            }

            shift += 7;
            ++size;
         }

         return size > tail_zero_bytes ? size - tail_zero_bytes : 0;
      }
   }
}