#include <string>
#include <iostream>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#include <emscripten/val.h>
#include <inttypes.h>
#include <string>
#include <iostream>

using namespace emscripten;

thread_local const val Uint8Array = val::global("Uint8Array");

EMSCRIPTEN_KEEPALIVE
extern "C" int processImage(std::string image_in) {
  uint8_t * image_buffer = (uint8_t*)(image_in.c_str());
//   std::cout << image_buffer << '\n';
  return 3;
}

#else 
int processImage(std::string image_in) {
	return 0;
}

int main() {
	return 0;
}
#endif
