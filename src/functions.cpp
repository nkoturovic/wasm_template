#include <string>
#include <iostream>

/* Mozjpeg stuff */
#include <jpeglib.h>


#include <turbojpeg.h>

void compress() {
	const int JPEG_QUALITY = 75;
	const int COLOR_COMPONENTS = 3;
	int _width = 1920;
	int _height = 1080;
	long unsigned int _jpegSize = 0;
	unsigned char* _compressedImage = NULL; //!< Memory is allocated by tjCompress2 if _jpegSize == 0
	unsigned char buffer[_width*_height*COLOR_COMPONENTS]; //!< Contains the uncompressed image

	tjhandle _jpegCompressor = tjInitCompress();

	tjCompress2(_jpegCompressor, buffer, _width, 0, _height, TJPF_RGB,
		  &_compressedImage, &_jpegSize, TJSAMP_444, JPEG_QUALITY,
		  TJFLAG_FASTDCT);

	tjDestroy(_jpegCompressor);

	//to free the memory allocated by TurboJPEG (either by tjAlloc(),
	//or by the Compress/Decompress) after you are done working on it:
	//tjFree(&_compressedImage);
	tjFree(_compressedImage);
}


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
//
	
  compress();
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
