#include <emscripten/val.h>
#include <inttypes.h>

thread_local const val Uint8Array = val::global("Uint8Array");

val processImage(std::string image_in) {
  uint8_t *image_buffer = static_cast<uint8_t>(image_in.c_str());
  return int8Array.new_(typed_memory_view(image_buffer, 256));
}
