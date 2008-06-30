// Copyright 2008 Keir Mierle, all rights reserved.
//
// Simple tests for the image wrapper class.

#include "libmv/image/image.h"
#include "testing/testing.h"

using libmv::Image;
using libmv::LoadImage;

namespace {

TEST(FailsOnNonexistantImage) {
  Image *image = LoadImage("non-existant-file");
  Check(!image);
}

TEST(Loads2x1Image) {
  Image *image = LoadImage("src/libmv/image/image_test_data.png");
  Check(image);
  Equals(2, image->Width());
  Equals(1, image->Height());
  Equals(8, image->Depth());
}

}  // namespace